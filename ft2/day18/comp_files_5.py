#! /usr/bin/python3
import glob
import os
import sys
#path_main = sys.argv[1]
#path_student = sys.argv[2]
path_main = "./"
path_student = "?"
#print(path_main, path_student)


names = sorted(glob.glob(path_student + '/*.c'))
length = len(names)
#print(names, end = '\n')
#print(length)
#sys.exit(0)
mylist = [ ]
j_set = set()
for i in range(length - 1):
	#print(i)
	temp_set = set()
	for j in range(i + 1, length) :
		#print(i, j)
		#print(i, j, j_set)
		if j in j_set and i in j_set: break
		status = os.system("diff -s -w -b -B " + names[i] + " " + names[j] + " > /dev/null")
		#status = os.system("diff -s -w -b -B " + names[i] + " " + names[j])
		if status == 0 :
			#print(i, j, names[i], names[j])
			temp_set.add(i)
			temp_set.add(j)
			j_set.add(i); j_set.add(j)
			#print(temp_set)
		
	if temp_set :
		mylist.append(list(sorted(temp_set))) 

#print(mylist, len(mylist))
for e in mylist:
	print("-" * 60)
	for i in e:
		print(names[i])
	print("-" * 60)

#print("over")				
			 
		
	
