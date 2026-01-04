#!/bin/bash
HSH=./hsh

run() {
  name="$1"
  input="$2"
  echo "== $name =="

  # run
  printf "%b" "$input" | $HSH >out 2>err
  code=$?

  echo "-- input --"
  printf "%b" "$input" | cat -e
  echo "-- stdout --"
  cat -e out
  echo "-- stderr --"
  cat -e err
  echo "-- exit code --"
  echo "$code"
  echo
}

run "exit only" "exit\n"
run "exit after not found" "qwerty\nexit\n"
run "exit 0" "exit 0\n"
run "exit 98" "exit 98\n"
run "exit 300 (mod 256)" "exit 300\n"
run "exit -1" "exit -1\n"
run "exit +12" "exit +12\n"
run "exit abc" "exit abc\n"
run "exit 12 extraArg" "exit 12 foo\n"
run "not found then exit 7" "qwerty\nexit 7\n"

