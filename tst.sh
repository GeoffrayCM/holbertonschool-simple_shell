cat > /tmp/x << 'EOF'
#!/bin/sh
exit 1
EOF
chmod +x /tmp/x

printf "exit 12 foo\n" | ./hsh; echo "code=$?"
printf "exit -1\n" | ./hsh; echo "code=$?"
printf "/tmp/x\nexit\n" | ./hsh; echo "code=$?"

rm -f /tmp/x

