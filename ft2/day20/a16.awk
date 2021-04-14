# process more than one file on the cmd line
# usage : awk -f <pgmname> dept.dat emp.dat
#{ print FILENAME, $0 }

BEGIN {
	FS=","
	# in place of , in print
	OFS=" dept is "
	# at the end of each print
	ORS="\n---------------------------------------\n"
}
FILENAME == "dept.dat" {
	dept[$1]=$2
}

FILENAME == "emp.dat" {
	print $2, dept[$4]
}

#END {
#	for(dname in dept)
#		print dept[dname]
#}
