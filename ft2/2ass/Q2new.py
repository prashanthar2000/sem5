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

  
for _ in range(4):
    Choice=input()
    Choice=Choice.split()
    if(Choice[0]=='a'):
        TAG = Choice[1]
        OCount = OpenedTags.count(TAG)
        CCount = ClosedTags.count(TAG)
        print(min(OCount,CCount))
    elif(Choice==['b']):
        Count_UnclosedTags = len(OpenedTags) - len(ClosedTags) - 1
        print(Count_UnclosedTags)
    elif(Choice==['c']):
        #Considering only values within the valid tags
        Values = re.findall(ValuesPat,data)
        # print(Values)
        ValidMatchCount = 0
        P1 = re.compile('\+{0}(\+{5})?(\?\?\?)+(\*\*)+')
        P2 = re.compile('\+{2}(\?\?)+(\*\*\*)+')
        for i in Values:
            if(P1.match(i) or P2.match(i)):
                ValidMatchCount+=1
                # print(i)
        print(ValidMatchCount)
    elif(Choice[0]=='d'):
        #Should the no of valid tags to be greater than 3
        #or than no of tags should tags 
        t = Choice[1]
        Depth = 0
        TAG = '<'+t+'>'
        CLOSETAG = '</'+t+'>'
        Pattern = TAG+'(.*?)'+CLOSETAG
        Matches = re.findall(Pattern,data,re.S)
        for i in Matches:
            # print(i)
            # print(len(re.findall(OpenTagPat,i)))
            # print(len(re.findall(ClosedTagPat,i)))
            # print('-'*20)
            if(max(len(re.findall(OpenTagPat,i)),len(re.findall(ClosedTagPat,i)))>=3):
                Depth+=1
        print(Depth)
    else:
        print("done")