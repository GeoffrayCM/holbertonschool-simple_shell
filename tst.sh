printf "qwerty\n" | ./hsh >/dev/null 2>/dev/null
echo "not found => $?"

tmp="/tmp/notexec_$RANDOM"
echo "echo hi" > "$tmp"
chmod 644 "$tmp"
printf "$tmp\n" | ./hsh >/dev/null 2>/dev/null
echo "perm denied => $?"
rm -f "$tmp"

