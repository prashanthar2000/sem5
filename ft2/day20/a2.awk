# display filename size; use ls -l as input
# display only if the file has more than 100
$5 > 100 # pattern and no action; default action : print
{ print $5, $8 } # no pattern ; action


# space acts like a concatenation operator

# considers this program to have two rules

# action should start on the same line as the pattern

