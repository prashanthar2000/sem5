# total for all batsmen
{
	total[$1] += $2
}
END {
	for(i in total)
		print i, total[i]
}
