import re
def mymatch(pat, texts):
	print("pattern : ", pat)
	for text in texts:
		m = re.search(pat, text)
		if m :
			print(text, m.group())
		#   0       1        2         3		
texts = [ 'cat', 'concat', 'cattle', 'catdogcat']
pat = 'cat'  # length : 3
#mymatch(pat, texts) # all 

# match cat in the beginning
# anchor : zerowidth pattern
# ^ : begin with
pat = '^cat' # 3
# mymatch(pat, texts) #  0, 2, 3

# [^0-9] : non digit

# 'cat^' => cat^
# 'cat\^' => cat^
# '\^cat' => ^cat
# '^^'    => start with ^
# '^[^^]' => begin with not a caret

# match at the end : anchor $
#           0       1         2         3
texts = [ 'cat', 'concat', 'cattle', 'catdogcat']
pat = 'cat$'
#mymatch(pat, texts)  # 0 1 3

# 
pat = '^cat$'
#mymatch(pat, texts)  # 0

# match cat in the beginning and cat at tne end
pat = '^cat.*cat$'
#mymatch(pat, texts)

#-----------------
texts = [ 'rama', 'rama krishna', 'ramakrishna', 'bala rama',
	'balarama', 'krishnaramagovinda', 'aaa rama bbb'
]
pat = 'rama'
#mymatch(pat, texts) # all

# match rama if it is a word all by itself
# anchors : zero width pattern; do not consume any space

# \b : word boundary
#\B : non word boundary
pat = r'\brama\b'  # 4 char pattern
#mymatch(pat, texts)
print("----" * 10)
pat = r'\Brama\B'  # 4 char pattern
#mymatch(pat, texts)

# ----------
pat = '\srama\s'
mymatch(pat, texts)

















		
