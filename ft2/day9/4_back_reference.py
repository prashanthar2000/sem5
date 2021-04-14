import re
def mymatch(pat, texts):
	print("pattern : ", pat)
	for text in texts:
		m = re.search(pat, text)
		if m :
			print(text, ":", m.group())
			#print(m.group(1))
			#print(m.group(2))
			#print(m.group(3))
			print(m.groups())  # tuple of strings
texts = [ 'hello' ]
pat = '..'
#mymatch(pat, texts)  # he

# char repeats ; two consecutive chars are same


# memory or back reference
#	enclosing in parentheses

# we use group(i) or groups() after pattern matching
texts = [ 'abcdefgh' ]
pat = '(....).(...)'
#mymatch(pat, texts)
# group(1) : abcd
# group(2) : fgh

texts = [ 'abcdefgh' ]
# leftmost parentheses decides the numbering
#      12   3    4 5
pat = '((..)(..))(.(..).)'
#mymatch(pat, texts) # ( abcd, ab, cd, efgh, fg )

# can we use memory while pattern matching
# back reference or recall
# \1 : recall the first matched variable
texts = [ 'hello' ]
pat = r'(.)\1'  # check whether two consecutive char are same
#mymatch(pat, texts)


# hello
# var 1 : h   e   l
# pat :   hh  ee  ll


# check whether the first two char are same
texts = [ 'hello', 'hhello' ]
pat = r'^(.)\1'
#mymatch(pat, texts)

#--------------------------

texts = [ 'ababab', 'abab', 'cccccc' ]
pat = r'(..)\1\1' # length : 6
#mymatch(pat, texts)

texts = ['abba', 'abcba', 'abaab' ] 
pat = r'(.)(.).?\2\1'
#mymatch(pat, texts)

#-------------
texts = ['host: www.google.com']
pat = r'host: (.*)'
#mymatch(pat, texts)


text  = 'host: 127.0.0.1 host: www.google.com host: pes.edu'
pat = r'host: ([\w.]+)'
print(re.findall(pat, text))



















			
