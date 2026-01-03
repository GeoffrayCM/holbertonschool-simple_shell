d=/tmp/ss_$RANDOM
mkdir -p "$d"
cat > "$d/ok" <<'EOF'
#!/bin/sh
echo OK
EOF
chmod 755 "$d/ok"
PATH="$d:$PATH" printf "ok\n" | ./hsh 2>&1 | cat -e
rm -rf "$d"

