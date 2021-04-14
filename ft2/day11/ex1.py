import re
text = """one two
three four
five six seven
eight nine
ten"""
# process line by line
# ^..*.$ : at least two char

# . does not match a newline by default
pat = r"^.*$"
m = re.search(pat, text)
if m :
	print(m.group())
else:
	print("no match")

# pickup the whole paragraph
# re.S : make . match a new line
pat = r"^.*$"
m = re.search(pat, text, re.S)
if m :
	print(m.group())  # one line
else:
	print("no match")
print("-" * 40)
	
#re.M : make $ and ^ meaningful for each line
# got the first line
pat = r"^.*$"
m = re.search(pat, text, re.M)
if m :
	print("matched : ", m.group())
else:
	print("no match")
print("-" * 40)
	
# get all lines
print(re.findall(pat, text, re.M))
print("-" * 40)


# walk thro the matches
for m in re.finditer(pat, text, re.M):
	print(m.group())
print("-" * 40)

	



	
