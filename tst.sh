printf "/tmp\n" | ./hsh 2>&1 | cat -e
printf "/tmp\n" | /bin/sh 2>&1 | cat -e

