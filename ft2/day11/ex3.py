import re
import sys
f = open("/etc/apache2/apache2.conf")
pats = ['Timeout', 'KeepAlive', 'MaxKeepAliveRequests', 'KeepAliveTimeout']
pat = "(" + "|".join(pats) + ")" + "\s+(\w+)"
print(pat)

#sys.exit()

kw = { }
for line in f:
	line = line.strip()
	line = re.sub(r'#.*$', '', line)
	m = re.search(pat, line)
	if m :
			#print(line, m.group(1), m.group(2))
			kw[m.group(1)] = m.group(2)
#	if line:
#		print(line)
f.close()
#"""
for k in kw.keys() :
	print(k, "=>", kw[k])
#"""
