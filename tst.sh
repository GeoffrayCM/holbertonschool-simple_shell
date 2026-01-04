cat << 'EOF' | ./hsh
/bin/false
exit
EOF
echo $?

