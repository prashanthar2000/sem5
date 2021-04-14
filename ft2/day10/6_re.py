# some examples
import re
s="""
module one
ondu
eradu
mooru
nalku
endmodule

module two
idu
aaru
elu
entu
endmodule

module three
ombattu
hattu
hannondu
endmodule
"""

"""
name = "one"
pat = "module " + name + ".*?endmodule"
m = re.search(pat, s, re.S)
if m :
	print(m.group())
else:
	print("not found")
"""
pat = "module " + "\w+" + ".*?endmodule"
#print(re.findall(pat, s, re.S))
l = re.findall(pat, s, re.S)
for e in l:
	print("---" * 20)
	print(e)
	print("---" * 20)

	

		
	
	
