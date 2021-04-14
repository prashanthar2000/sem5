# display filename size; use ls -l as input
# display only if the file has more than 100
# for a record of input, each rule is applied in turn
# next : will cause reading of the next record of the
# file and again start from the first rule
$5 > 100 { 
   print $5, $8 
   next
} 


$5 > 50 { 
   print $5, $8 
} 


