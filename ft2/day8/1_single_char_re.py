# single char regular expression
import re

# 't'  => matches t
# '\t' => matches tab
# '\'  =>  error
# '\\' => matches \
# \ : escape sequence
#	either to give  a special meaning
#	remove special meaning
#	what is special : depends on the context

"""
# some issue with r and \
text = r"abc\pqr"
pat = r'c\p'
print(pat)
m = re.search(pat, text)
if m :
	print("match successful")
else:
	print("match failed")
"""

# check whether a text string has a lowercase vowel
# a or e or i or o or u
# pattern = 'a|e|i|o|u'
# | : alternator ; match one of these
# Rules of pattern matching
# Rule 1 :
#	find the leftmost match
#	match from text to pattern

"""
text = "heat"
pat = "a|e|i|o|u"
print(pat)
m = re.search(pat, text)
if m :
	print("match successful")
	print("matched char : ", m.group()) # e
else:
	print("match failed")
"""

"""
# alternator is too powerful 
# check whether one of the chars occurs, we use character class
# is a set
# no repetitions
# [aeiou]
text = "heat"
pat = "[aeiou]"
print(pat)
m = re.search(pat, text)
if m :
	print("match successful")
	print("matched char : ", m.group()) # e
else:
	print("match failed")

# 'aaa' : three consecutive a
# 'a' : single a
# '[aaa]' : single a 
"""

# match a digit
#pat = "[0123456789]" # character class
# cannot be 0123456789

"""
text = "25"
#pat = "[0123456789]"
pat = "[0-9]"  # - range ; special in the middle of a char class
print(pat)
m = re.search(pat, text)
if m :
	print("match successful")
	print("matched char : ", m.group()) # 2
else:
	print("match failed")

# [09-]  : - not special at the end of a char class ; 0 or 9 or -
# [09\-] : - does not become special at the end of char class : 0 or 9 or -
# [0\-9] : escaping will remove the special meaning : 0 or 9 or -
"""

"""
# [0-9] for a digit
# [^0-9] a non digit   # match anything other than a digit
# ^ : context as the first char of char class : inverts the pattern matching

# [abc] : a or b or c
# [^abc] : anything other than a or b or c

# [^^] : match anything other than a ^
# [^\^] : match anything other than a ^
# [\^\^] : matches a ^
# [\^^] : matches a ^ (caret)

# ^ and ? : have 3 meanings in regular expression
"""

#-------------------------
# macros
# digit : [0-9]   \d
# non digit : [^0-9]   \D
# word char : [A-Za-z0-9_]  \w
# non word char : [^A-Za-z0-9_]  \W
# space char : [ \t\n\r\f]  \s
# non space char : [^ \t\n\r\f] \S

# -------------------
# text : 123ABC
# pat : \d\D     : match : digit and non digit : contiguous  3A
# pat : [\d\D]   : match : anything ; leftmost : 1

def mymatch(pat, texts):
	print("pattern : ", pat)
	for text in texts:
		m = re.search(pat, text)
		if m :
			print(text, m.group())
"""			
texts = ["0", "9", "-", "5", "." ]
pat = "[0-9]"
mymatch(pat, texts)
"""
#			0      1      2      3     4       5     6    7
"""
texts = [ "c?t", "cat", "c.t", "ct", "coat", "c+t", "c", "t" ]
pat = "c?t"
mymatch(pat, texts)
"""

# shell : ? : stands for a char
# regex : ? : has 3 meanings depending on the context
#		what precedes is optional
#	c?t : ct or t
#   matched all as c is there in each

# match c and then any char and then t
texts = [ "c?t", "cat", "c.t", "ct", "coat", "c+t", "c", "t" ]
pat = "c.t"
# regex : . matches any one char
mymatch(pat, texts)


































