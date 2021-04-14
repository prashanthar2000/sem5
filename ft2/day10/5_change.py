# parentheses:
#	- back reference and memory
#	- grouping

# strings are immutable in Python

import re
# substitute :
text = "bad course bad teacher bad timings"
pat = 'bad'
# replace the text
text = re.sub(pat, 'worse', text) # returns the changed string
# by default, changes all occurrences
print(text)

text = "bad course bad teacher bad timings"
pat = 'bad'
# replace the text
text = re.sub(pat, 'worse', text, count = 2) # returns the changed string
print(text)

#---------------
# re.sub(pattern, string or callable, ...)
# callable is called with a match object
# should return a string back

def foo(m):
	print("m:", m)
	return "eradu"
	
text = "one two three"
pat = "two"
text = re.sub(pat, foo, text)
print("text : ", text)

#---------------
s = "AB" # hex # ?  convert to decimal
n = int(s, 16)
print(n)
#-------------------

#  a+b%c  in URL
#	encoded  a%2Bb%25c

s = "a%2Bb%25c"
s = re.sub('%..', "", s)
print(s)
# 2B : 2 % 16 + 11 = 43 => ASCII of +
print(int("2B", 16))
print(chr(int("2B", 16)))

def my_change(m):
	return "XX"
	
s = "a%2Bb%25c"
s = re.sub('%..', my_change, s)
print(s)

def my_change1(m):
	return chr(int(m.group(1), 16))
	
s = "a%2Bb%25c"
s = re.sub('%(..)', my_change1, s)
print(s)





















