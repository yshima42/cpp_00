#!/bin/bash

make
./bank > log

cut -d ' ' -f 2- log > no_timestamp.log
cut -d ' ' -f 2- 19920104_091532.log > intra_no_timestamp.log

diff no_timestamp.log intra_no_timestamp.log

rm log no_timestamp.log intra_no_timestamp.log
