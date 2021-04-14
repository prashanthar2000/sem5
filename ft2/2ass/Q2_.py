import sys
import re 

TagPat          =   '<[^>]+>'
OpenTagPat      =   '<([^/^>]+)>'
ClosedTagPat    =   '</([^>]+)>'
ValuesPat       =   '<[^/^>]+>(.*)</[^>]+>'
Validate        =   '\?{0}'

fp  = open(sys.argv[1])
data= fp.read()

OpenedTags  = re.findall(OpenTagPat,data)
ClosedTags  = re.findall(ClosedTagPat,data)

# a Should the output be no of valid tags or just tags?
# b The tags that are opened and not closed to be Counted aste

# c the values in between tags that are not closed also to be considered
# d Count of tags which has three depth 


UnClosedTags = dict()
for i in range(len(OpenedTags)):
    if(OpenedTags[i] in UnClosedTags):
        UnClosedTags[OpenedTags[i]] += 1
    else:
        UnClosedTags[OpenedTags[i]] = 1
for i in range(len(ClosedTags)):
    temp=ClosedTags[i].replace('/','')
    if(temp in UnClosedTags):
        UnClosedTags[temp] -= 1 
Count_2=0
for i in UnClosedTags.keys():
    if(UnClosedTags[i]!=0):
        Count_2+= UnClosedTags[i]
        # print(i)
# print("OPENED TAGS",OpenedTags)
# print("CLOSED TAGS",ClosedTags)
Values = re.findall(ValuesPat,data)
print(Values) 

NestedValuesPat =   '<tag3>(.*?)<\/tag3>'
m = re.findall(NestedValuesPat,data,re.S)
print(type(m) , len(m))
for i in m:
    #for j in i:
    print(i)
    print('-'*50)
         

#for i in m:
#    print(i) 
