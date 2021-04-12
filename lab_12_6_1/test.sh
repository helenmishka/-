#!/bin/bash
for (( i = 1; i <= 5; i++ ))
do
echo test\#$i:
file_in="./ftest/in_$i.txt"
file_out="./ftest/out_$i.txt"
./app.exe < $file_in > out.txt
diff -s out.txt $file_out
done