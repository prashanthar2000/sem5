# look for awk files only
# use ls -l
$9 ~ /awk/ { print $9 }
