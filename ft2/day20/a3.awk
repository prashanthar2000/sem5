# display filename size; use ls -l as input
# display only if the file has more than 100
$5 > 100 { 
   print $5, $8 
} 


