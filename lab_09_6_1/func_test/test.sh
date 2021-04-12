#!/bin/bash
for (( i = 1; i <= 5; i++ ))
do
echo test\#$i:
file_in="./in_$i.txt"
file_out="./out_$i.txt"
./app.exe < $file_in > out.txt
diff -s out.txt $file_out
done