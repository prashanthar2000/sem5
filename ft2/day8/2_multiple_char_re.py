# regular expression:
#	mastering regular expression : Oreilly
#	~ 600 pages

# single char regular expression
import re
def mymatch(pat, texts):
	print("pattern : ", pat)
	for text in texts:
		m = re.search(pat, text)
		if m :
			print(text, m.group())

"""
#			0       1      2      3		  4	
texts = ["ab*d", "abcd", "ad", "abbbd", "cad"  ]
pat = "ab*d"
mymatch(pat, texts) # 2 3 4
"""


# grep <pattern> <files...>
# grep "ab*d" ab*d
# * :
#	shell:
#		* : any char any number of times
#		ab*d
#		all files whose names start from ab and end with d
#	re:	
#		* : zero or more of whatever  precedes * ;  closure
#		ab*d
#		a followed by 0 or more b and then a d

"""
texts = ["ab*d", "abcd", "ad", "abbbd", "cad"  ]
pat = "ab+d"  #  positive closure; 1 or more of what precedes it
mymatch(pat, texts) # 3
"""

# decimal integer constant:
#	optional sign + or -
#	one or more digits
#	[+-]?\d+

"""
# counting closure

texts = ["ad", "abd", "abbd", "abbbd", "abbbbd"  ]
pat = "ab{2}d"  #  counting closure;  
mymatch(pat, texts) # 
"""
"""
texts = ["ad", "abd", "abbd", "abbbd", "abbbbd"  ]
pat = "ab{2,4}d"  #  counting closure with range  
mymatch(pat, texts) # 
"""

# rules of pattern matching
# shell : * matches any char any # of times
# re : 
#	1. leftmost match
#	2. eager
#	3. greedy
#		re engine backtracks char by char to match the remaining pattern

"""
texts = [ "axxxbyyybzzz" ]
pat = "a.*b"
mymatch(pat, texts)
"""

#	axxxbyyybzzz
#	a.*b
#	matched : axxxbyyyb

# lexical analyzer : first phase of compiler
#	a---b   'C'
#	a : identifier
#	- : operator
#	-- : yes; operator
#	--- ; NO
#	-- : token(operator)
#	- : operator
#	-b as one unit : NO
#	- : operator
#	b : identifier

# a---b   => a-- - b

# ---------------
"""
template<typename T, typename A<T>>
class A
{
};
"""
"""
# do not want a greedy match
texts = [ "axxxbyyybzzz" ]
pat = "a.*?b"
mymatch(pat, texts)
"""

# axxxbyyybzzz
# a.*?b
# leftmost, eager, non greedy
# does a  forward track until the remaining pattern is matched

texts = ["good food"]
pat = "o+"  # oo of good
mymatch(pat, texts)

texts = ["good food"]
pat = "o*"  #  matches nothing successfully
mymatch(pat, texts)



























