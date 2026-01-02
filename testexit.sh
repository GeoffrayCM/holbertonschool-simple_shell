#!/bin/bash
printf "exit 42\n" | ./a.out ; echo $?
printf "exit 999\n" | ./a.out ; echo $?
printf "exit -1\n" | ./a.out ; echo $?
printf "exit 0\n" | ./a.out ; echo $?
printf "exit\n" | ./a.out ; echo $?
printf "exit 256\n" | ./a.out ; echo $?
printf "exit 98\n" | ./a.out ; echo $?
