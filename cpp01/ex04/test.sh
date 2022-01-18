#!/bin/bash

printf "5 arguments\n"
./replace tests/test1.txt aa bb bbbbbbb
printf "\n"

printf "file dose not exist\n"
./replace tests/no_file a b
printf "\n"

printf "test1.txt s1 null string\n"
./replace tests/test1.txt "" abc
printf "\n"

printf "test1.txt s2 null string\n"
./replace tests/test1.txt abc ""
printf "\n"

printf "test1.txt simple test\n"
./replace tests/test1.txt a hello
diff -y --suppress-common-lines tests/test1.txt tests/test1.txt.replace 
printf "\n"

printf "test1.txt s1 == s2\n"
./replace tests/test1.txt a a
diff -y --suppress-common-lines tests/test1.txt tests/test1.txt.replace
printf "\n"

printf "test1.txt s1 dose not exist\n"
./replace tests/test1.txt pp bb 
diff -y --suppress-common-lines tests/test1.txt tests/test1.txt.replace
printf "\n"

printf "test2.txt simple test\n"
./replace tests/test2.txt hello HELLO
diff -y --suppress-common-lines tests/test2.txt tests/test2.txt.replace 
printf "\n"

printf "test2.txt s1 dose not exit\n"
./replace tests/test2.txt HELLO aaa
diff -y --suppress-common-lines tests/test2.txt tests/test2.txt.replace
printf "\n"

printf "test3(empty file) simple test\n"
./replace tests/test3.txt a b 
diff -y --suppress-common-lines tests/test3.txt tests/test3.txt.replace
printf "\n"

rm tests/test1.txt.replace tests/test2.txt.replace tests/test3.txt.replace
