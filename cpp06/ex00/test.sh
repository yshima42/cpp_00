#!/bin/bash

make test

while read line
do
    ./convert $line
done < corvvs_cases.txt

make fclean

