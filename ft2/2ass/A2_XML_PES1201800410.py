#! /usr/bin/python3.8

import sys
import re

fp = open(sys.argv[1],'r' )
lines = fp.readlines()
# print(lines)


######## should not have multiple start and end tag in a same line#####
def noOfOccurence(lines, tag):
    # count = 0
    tag_count = 0
    start_tag = '<' + tag + '>'
    # end_tag = '<\\' + tag + '>'
    for line in lines:
        start = re.search(start_tag, line)
        while (start):
            # print(start)
            tag_count += 1
            line = re.sub(start_tag , '' , line)
            start = re.search(start_tag, line)
    return tag_count    


def unClosedTags(lines):
    count = 0
    start_tag = '<([^/]*?)>'
    end_tag = '</(.*?)>'
    open_tag = {}
    # close_tag = set()


    for line in lines:
        start = re.search(start_tag , line)
        while (start):
            # print(start)
            tag = start.group(1)
            if tag in open_tag:
                open_tag[tag] += 1
            else:
                open_tag[tag] = 1
            
            line = re.sub(start_tag , '' , line)
            start = re.search(start_tag, line)
        end = re.search(end_tag, line)
        while (end):
            # print(end)
            tag =  end.group(1)
            if tag in open_tag:
                if open_tag[tag] == 1:
                    del open_tag[tag]
                else:
                    open_tag[tag] -= 1
            
            # if end.group(1) in open_tag:
                # count += 1 
                # open_tag.discard(end.group(1))
            line = re.sub(end_tag , '' , line)
            end = re.search(end_tag, line)
        
    for i in open_tag:
        count += open_tag[i]
    
    # print(open_tag)
    return count -1  

def tagsWithSpecificPattern(lines):
    pattern1 = r"(\+\+\+\+\+)?(\?\?\?)+(\*\*)+"
    pattern2 = r"\+\+(\?\?)+(\*\*\*)+"
    open_tag = r'<([^/].*?)>'
    close_tag = r'</\1>'
    # close_tag = r'\1'
    pattern = open_tag + '\s*(' + pattern1 + "|" + pattern2 + ")\s*" + close_tag
    # pattern = open_tag + '\s*(' + pattern1 + "|" + pattern2 + ")\s*"
    # pattern = open_tag + '\s*(' + pattern1 + "|" + pattern2 + ")\s*" + close_tag + '>'
    # print(pattern)  
    # pattern1 = r'(+|+++++)?'
    # pattern2 = r'++'
    count = 0 
    for line in lines:
        # m = re.search(pattern1, line)
        m = re.search(pattern , line )
        if m:
            # print(m)
            count += 1
            
        # else:
        #     n = re.search(pattern2, line)
        #     if n:
        #         count += 1
            
        # print(n , m , sep="\n")

    return count

def tagsWithDepthOF3(lines, tag):
    count = 0 # to find the no of tags with depth 1 (relative to tag(eg tag3))
    main_count = 0 # to count...... basically the end result 
    d = {} # to keep track of tags
    depth =  0#see if we are inside the given tag
    inside_tag = (0 , 0) #to find manage the inside tag closing tags
    start_or_end = 1 # same as depth , search for start tag if 1 else end tag

    # main_tag_start = '<' + tag + '>'
    # main_tag_end  = '</' + tag + '>'
    start_tag = '<([^/]*?)>'
    end_tag = '</(.*?)>'

    depth4tag = ""


    for line in lines:
        # print(main_count, count ,depth , inside_tag,  line )
        if depth < 4:
            m = re.search(start_tag ,line)
            if m:
                # print(m , m.group(1)==tag)
                if inside_tag == (1 , depth ):
                    count += 1 
                depth += 1
                # print(inside_tag , (1, depth -1 ))
                
                if depth == 4:
                    depth4tag = m.group(1)
                
                if m.group(1) == tag:
                    inside_tag = (1 , depth)
                
            n = re.search(end_tag, line)
            if n:
                depth -= 1
                if n.group(1) == tag:
                    if count > 2:
                        main_count += 1 
                        count = 0 
                    inside_tag  = (0 , 0)
                # elif inside_tag:
                #     pass
                    

        # elif depth >= 4:
        else:
            found_tag = 0
            n = re.search(end_tag, line)
            if n:
                if n.group(1) == depth4tag:
                    depth -= 1
                if n.group(1) == tag:    
                    inside_tag  = (0 , 0)
                    if count > 2:
                        main_count += 1 
                        count = 0 
                else:
                    found_tag = 1 


            m = re.search(start_tag, line)
            if m:
                # print(m)
                if inside_tag == (1 , depth ):
                    count += 1 


    return main_count 



input_values = {}
# for _ in range(4):

a = input()
l = a.split()
input_values[l[0]] = l[1]
a = input()
a = input()
a = input()
l = a.split()
input_values[l[0]] = l[1]
# print(input_values)

a = noOfOccurence(lines , input_values['a'] )
print(a)
b = unClosedTags(lines)
print(b)
c = tagsWithSpecificPattern(lines)
print(c)

d = tagsWithDepthOF3(lines , input_values['d'])
print(d)