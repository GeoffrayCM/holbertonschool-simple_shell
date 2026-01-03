cat << 'EOF' | ./hsh
exit
EOF
echo "status=$?"
cat << 'EOF' | ./hsh
exit 98
EOF
echo "status=$?"
cat << 'EOF' | ./hsh
exit 300
EOF
echo "status=$?"
cat << 'EOF' | ./hsh 2>err
exit -1
EOF
echo "status=$?"
cat -e err
cat << 'EOF' | ./hsh 2>err
exit abc
EOF
echo "status=$?"
cat -e err

