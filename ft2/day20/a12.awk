# create an associate array
# awk -f a12.awk emp.dat
BEGIN {
	FS=","
}
{
	a[$2]=$3
}
END {
	for(name in a)
		#print name, a[name] | "sort" # order of name
        #	print  a[name], name | "sort -n -r" # order of sal
		print   name,  a[name] | "sort -n -r -k 2" # order of sal
}

# pipe thro a OS cmd
