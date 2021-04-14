cipher = "44 54 11 34 54 11 23 33 53 44 54 12 42 43 42 44 32 51 41 21 23 11 31 13 53 15 54 42 54 42 44 42 43 44 32 51 41 53 43 54 32 42 34 41 11 25 51 35 53 34 13 42 43 22 53 43 11 44 54 34 53 43 22 51 34 31 42 14 32 51 34 12 53 34 12 15 54 15 34 51 33 51 44 44 11 22 51 44 42 54 42 44 44 15 34 51 23 55 15 43 21 34 51 11 13 11 21 23 51 42 54 31 53 33 21 42 43 51 44 53 15 34 14 34 51 25 42 53 15 44 33 51 54 32 53 41 44 34 35 13 54"
cipher =  list(map(int , cipher.split()))
#print(cipher)
#get unique
s = list(set(cipher))
print(len(s))
d = {}
count = 65
for i in s:
    d[i] = chr(count)
    count += 1
for i in cipher:
    print(d[i] , end="")
    
    
#solve substition cipher online using output as cipher text //https://www.boxentriq.com/code-breaking/cryptogram
solution = """ 
start almost finished black out it is in shed on third ave working on a stronger cipher for future messages it is surely unbreakable it combine sour previous methods rwkt   
""" 
