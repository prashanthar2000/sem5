#! /bin/bash
for name in ?/*.c ;
do
	newname=`echo $name | tr " ()'" "_"`
#	echo $newname 
	mv "$name" "$newname"
done
