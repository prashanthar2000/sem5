# read using getline
# when the end of file is reached, getline returns 0
BEGIN {
	while (getline line < "dept.dat" > 0) 
	{
		print line
	}
}
