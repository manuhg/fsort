#!/usr/bin/zsh
[ -f temp.txt ] && rm temp.txt
find "$1" -type f -exec echo {} \; > temp.txt
sed "s/$/ 0/" temp.txt > file_list.txt
rm temp.txt
./fsort_fe $(wc -l file_list.txt | cut -f 1 -d ' ')
