import re
# check for pattern in text
text = "together"
pat = "get"

# re.search(pattern, text) => match object or None

"""
m = re.search(pat, text)
if m :
	print("match successful")
else:
	printf("match failed")
	
pat = "got"
m = re.search(pat, text)
if m :
	print("match successful")
else:
	print("match failed")
"""

text = "together"
#       01234567
pat = "get"
m = re.search(pat, text)
if m :
	print("match successful")
	#print(m.span())  # (2, 5)
	print("before match : ", text[ :m.span()[0]])
	print("matched : ", text[m.span()[0] : m.span()[1]])
	print("after match : ", text[m.span()[1] :])
	
	print("matched : ", m.group())
	
else:
	printf("match failed")

# string
#	1. single quoted string 'pes'
#	2. double quoted string "pes"
#		there is no difference bet single and double quotes
#	3. triple quotes (using single or double quotes)
#		multiple lines
#	4. raw string
#	prefix r before the quotes in the string
#	escape sequences are not expanded


a = "rama\nkrishna" # got expanded
print("a : ", a)
b = r"rama\nkrishna" # not expanded
print("b : ", b)






# shell :
#	double quotes: variable is substituted or interpolated;
#					escape sequence is expanded
#	single quotes : variable is not substituted
#					escape is not expanded


	
