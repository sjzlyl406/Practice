#########################################################################
# File Name: index.sh
# Author: leon
# mail: sjzlyl406@163.com
# Created Time: 2015年07月30日 星期四 19时22分20秒
#########################################################################
#!/bin/bash

Dir=index.txt
if [ ! -s $Dir ] 
then
	echo > $Dir
fi

for file in `ls | grep 'test'`
do
#	file=testi.c
	echo "$file" >> $Dir
	sed -n '8,/\s\*\s\*/p' $file >> $Dir
	echo ' ' >> $Dir
done
