# find sum of sizes of the file
# also find average file size

# remove the first line
# method 1
# NR != 1 { print NR, $9, $5 }

# method 2
# NR == 1 {
# 	next 
# }

NR == 1 { next }
# variable initialized to 0 by default
BEGIN {
	sum = 0
	
}
{
   sum = sum + $5
   i ++
 #  print sum  # outputs cumulative sum
}
END {
	print "sum is : ", sum
	print "# of files  ", i
	# supports floating point arithmetic
	print "average size : ", sum / i
	print NR
	print "average size : ", sum / (NR - 1)
	printf "average size : %8.2f\n", sum / i

}


{ print NR, $9, $5 }



