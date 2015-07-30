#########################################################################
# File Name: index.sh
# Author: leon
# mail: sjzlyl406@163.com
# Created Time: 2015年07月30日 星期四 19时22分20秒
#########################################################################
#!/bin/bash

for file in `ls | grep 'test'`
do
#	file=testi.c
	echo "$file" >> a.txt
	sed -n '8,/\s\*\s\*/p' $file >> a.txt
	echo ' ' >> a.txt
done
