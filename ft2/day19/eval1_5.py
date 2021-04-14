#! /usr/bin/python3
import os
import glob
import sys
import time

#path_main = sys.argv[1]
#path_student = path_main + "/" + sys.argv[2]
path_main = "./"
path_student = "?"

 
names = sorted(glob.glob(path_main + path_student + '/*.c'))
#print(names)
#print(len(names))

test_files = sorted(glob.glob(path_main + '/in*.txt'))
res_files = sorted(glob.glob(path_main + '/out*.txt'))


#print(names, end = '\n')
#print()
print(test_files, end = '\n')
print()
print(res_files, end = '\n')
print()

#sys.exit(0)

outfile = open("eval_res.dat", "w")
status = os.system("gcc -c " + path_main + "5amain.c -o main.o") 
#status = os.system("gcc -c " + path_main + "main.c -o main.o") 
if status != 0 :
	print("cannot create object file")
	sys.exit(0)
	
for name in names:
	score = []
	for (test, res) in map(lambda x, y : (x, y), test_files, res_files) :
		#print(test, res)
		print(name)
		status = os.system("gcc " + name + " " +  "main.o " + "-lm " + " 2>/dev/null")
		if status != 0 :
			print("\n\ncannot compile and link", name, file = outfile) 
			break
		
		#status = os.system("./a.out <" + test  + " >out.txt")
		pid = os.fork()
		if pid:
			time.sleep(0.1)
			os.kill(pid, 16)
			(pid, x) = os.wait()
			#print(x)
			signal = x & 0xff
			status = x >> 8
			#print(status, signal)
		else:
			#print(test, res)
			os.execvp("./a.out", (test, "./zzz.dat"))
#		if status != 0 and signal != 0:
		if status != 0:
			print("cannot run : ", name, file = outfile)
			
		else:
			#print("----")
			#os.system("cat ./zzz.dat")
			#print("----")
			status = os.system("cmp -s " + "./zzz.dat " + res)
			if status == 0 :
				score.append(10)
			else:
				score.append(0)
	print(name, score, sum(score))
	#print(name, score, sum(score))
	print(name, file = outfile, end = ",")
#	for s in score:
#		print(s, file = outfile, end = ",")
	for i in range(len(score)):
		#if (i == 0 or i == 1) and score[i] == 10 :
		#	score[i] = 5
		print(score[i],  end = ",")
		print(score[i], file = outfile, end = ",")
	print(sum(score), file = outfile)
	print(sum(score))

	
outfile.close()
			 

			
