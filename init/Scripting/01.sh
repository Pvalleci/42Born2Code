cat /etc/passwd | awk -F ":" '{$2 "" ; print $1; print $3; print $6; print $10}'
