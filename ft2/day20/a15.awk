# data file is place.dat
# key is unique
#	support multiple values for a given key
{
	if( visit[$1])
		visit[$1]=visit[$1] ":"  $2
	else
		visit[$1]=$2
}
END {
	for(city in visit)	{

	#	print city, visit[city]
		print city
		temp=visit[city]
		split(temp, places, /:/)
		for(place in places)
			print "      ", places[place] 
	}
}

