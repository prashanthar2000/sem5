# use /etc/passwd
# also set -F:
BEGIN {
	FS=":"
}

$1 == "nsk" {
	print
}

