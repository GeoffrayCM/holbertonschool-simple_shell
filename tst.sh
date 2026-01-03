#!/bin/bash
set -u

HSH=./hsh

run_case () {
  name="$1"
  input="$2"
  expected="$3"

  printf "%b" "$input" | $HSH >/dev/null 2>/dev/null
  got=$?

  if [ "$got" -eq "$expected" ]; then
    echo "OK: $name => $got"
  else
    echo "FAIL: $name => got $got expected $expected"
  fi
}

echo "== Basic exit statuses =="

# 0) EOF => 0
printf "" | $HSH >/dev/null 2>/dev/null
echo "EOF => $?"

# 1) not found => 127
run_case "not found" "qwerty\n" 127

# 2) direct path missing => 127
run_case "missing direct path" "/bin/qwerty\n" 127

# 3) direct path permission denied => 126
tmp="/tmp/notexec_$RANDOM"
echo "echo hi" > "$tmp"
chmod 644 "$tmp"
run_case "direct path not executable" "$tmp\n" 126
rm -f "$tmp"

# 4) directory executed => 126 (common checker)
run_case "execute directory" "/tmp\n" 126

# 5) found via PATH but not executable => 126
d="/tmp/ss_$RANDOM"
mkdir -p "$d"
echo "echo hi" > "$d/zz"
chmod 644 "$d/zz"
PATH="$d:$PATH" run_case "PATH hit but not executable" "zz\n" 126
rm -rf "$d"

# 6) success => 0
run_case "success /bin/true" "/bin/true\n" 0

echo "== Done =="

