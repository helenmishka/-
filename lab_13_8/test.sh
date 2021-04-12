#!/bin/bash
for (( i = 1; i <= 4; i++ ))
do
echo test_s\#$i:
file_in="./ftest/in_$i.txt"
file_out="./ftest/out_$i.txt"
./app_s.exe < $file_in > out.txt
diff -s out.txt $file_out
done

for (( i = 1; i <= 4; i++ ))
do
echo test_d\#$i:
file_in="./ftest/in_$i.txt"
file_out="./ftest/out_$i.txt"
./app_d.exe < $file_in > out.txt
diff -s out.txt $file_out
done

for (( i = 1; i <= 4; i++ ))
do
echo test_l\#$i:
file_in="./ftest/in_$i.txt"
file_out="./ftest/out_$i.txt"
./app_l.exe < $file_in > out.txt
diff -s out.txt $file_out
done