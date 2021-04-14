import re
f = open("/etc/apache2/apache2.conf")
pats = ['Timeout', 'KeepAlive', 'MaxKeepAliveRequests', 'KeepAliveTimeout']
kw = { }
for line in f:
	line = line.strip()
	line = re.sub(r'#.*$', '', line)
	for k in pats:
		pat = k + '\s+' + '(\w+)'
		m = re.search(pat, line)
		if m :
			#print(line, m.group(1))
			kw[k] = m.group(1)
#	if line:
#		print(line)
f.close()
for k in kw.keys() :
	print(k, "=>", kw[k])
	
