ifconfig en0 | grep "inet " | cut -d " " -f6
ping 10.11.255.255 | arp -a | cut -d '(' -f2 | cut -d ')' -f1 | grep '10.*'
