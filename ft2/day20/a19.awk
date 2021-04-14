# awk -f a=$var -f a19.awk
BEGIN {
#	print "a : ", a
	print a * a, a * a * a
}
