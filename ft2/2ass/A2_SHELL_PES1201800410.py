#! /usr/bin/python3.7

import sys 
import re

#debug purpose
def disp(_listvar):
    for i in _listvar:
        print(repr(i))

#remove empty line , extra spaces at the end of line and comments
def remove_comment(text):
    text = re.sub(r'#.*', "",text)
    text = re.sub(r"\s*$", "" , text)
    return text 


#see if the 1st line has shebang
def hasshebang(text):
    if re.search('^#!', text):
        return text[:-1]
    return remove_comment(text)



fp = open(sys.argv[1] , 'r')

i = fp.readline()

# find if shebang present 
first_pass = hasshebang(i)
if first_pass == "":
    first_pass = []  
else:
    first_pass = [first_pass]

for i in fp.readlines():
    temp = remove_comment(i)
    if temp != "":
        first_pass.append(temp)

fp.close()

# disp(first_pass)
# print('-'*20 + "remove if-fi" + '-'*20)

#remove if-fi
###############flaw it can't process if fi statement starting with quote or a double quote#####
def remove_if(texts):
    is_if = 0 # tell no of if 1 for normal , 2... for nexted if statements
    second_pass = []#output list
    for i in texts:
        if re.search(r"(^|\s+|;)if\s+", i):
            is_if += 1
            m = re.search(r"(^|\s*|;)if.*(\s|;)fi(\s+|$)", i) #search for if and fi in the same line
            if m:
                if m.group(1) == ";":
                    i = re.sub(r"(^|\s*|;)if.*(\s|;)fi(\s+|$)" , ";" , i) #substitue if ... to ... fi with ""
                else:
                    i = re.sub(r"(^|\s*|;)if.*(\s|;)fi(\s+|$)" , "" , i)        
                second_pass.append(i)
                is_if -= 1
        
        elif re.search(r"fi", i):
            is_if -= 1
        elif not is_if:
            second_pass.append(i)

    return second_pass
                
# second_pass = remove_if(first_pass)
# disp(second_pass)
# print('-'*20 , "remove dummy function" , '-'*20)

#remove redundant
#####################same as if-fi one doesn't check if it has nested {} or if it is incide quotes##
def remove_rdnt_func(texts):
    third_pass = []
    # d = {} 
    # func_name = "" #to hold function name
    is_func = 1 #are we inside a function? 0 is yes 1 is no , so initially no  
    bracket_count = 0 #to count the number of brackets
    for i in texts: 
        #see if we are inside the function
        if is_func:
                        
            m = re.search(r".*?\(\)", i)
            if m:
                is_func = 0
                func_name = i
            else:
                third_pass.append(i)
        #see if it is the 1st line after function definition        
        elif "{" in i:
            third_pass.append(func_name)
            third_pass.append(i)
            bracket_count = 1
        #check if it the last line of the function
        elif '}' == i:
            is_func = 1
            if(bracket_count):
                #if last one in the list is open bracket , then there is nothing in the function
                #there fore pop 2 elements out
                if(third_pass[-1] == "{"):
                    third_pass.pop()
                    third_pass.pop()
                else:
                    third_pass.append(i)
                bracket_count = 0
        #if we are incide the bracket 
        elif bracket_count:
            third_pass.append(i)

    return third_pass


# third_pass = remove_rdnt_func(second_pass)
# disp(third_pass)
# print('-'*20 , "Take care of alias" , '-'*20)

def rdnt_alias(texts):
    final_pass  = []
    d = {}# format => {alias_name:(alias_value , type_of_quote_used , line_number_to_append )
    
    for i in texts:
        m = re.search(r"alias\s+(.*?)=([\"\'])(.*?)[\"\']" , i )
        if m:
            d[m.group(1)] = (m.group(3) , m.group(2) , len(final_pass))
        else:
            final_pass.append(i)
    
    
    #find all the alias which has x recursively and delete then if the do
    def find_rec(x , d): 
        if x in d:
            a = d[x]
            del d[x]
            #create new dict which doesn't have a[0] as its value
            d = {k:v for k , v  in d.items() if v[0] != a[0]}
            
            return find_rec(a[0], d)
        else:
            return x , d
    
    l = []
    if d:
        l = next(iter(d))
    #while there is still elements to process 
    while(l):
        quote = d[l][1]
        line_number = d[l][2]
        
        a , d = find_rec(l , d)
        final_pass.insert(line_number , "alias " + l + "=" + quote + a + quote)
        if d:
            l = next(iter(d))
        else:
            l = []
        
    
    return final_pass
        


first_pass = remove_if(first_pass)
first_pass = remove_rdnt_func(first_pass)

first_pass = rdnt_alias(first_pass)

#write back the processed file into a new file
fp = open('PES1201800410_A2.sh' , "w")

for i in first_pass:
    print(i , file=fp)

fp.close()

#print the output of the file which we just wrote
for i in first_pass:
    print(i)

