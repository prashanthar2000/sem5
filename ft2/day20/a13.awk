# total for sourav
$1 == "sourav" { total += $2 }

# $1 ~ /sourav/

END { print total }
