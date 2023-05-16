###2
# #! /bin/bash
# #每次push之前先运行此脚本
# for num in $*
# do
#     all=$(ls algorithms|sort -n)
#     line=$(echo "${all}"|grep -n "^${num}\..*")
#     echo "${line}"
#     title=`echo ${line}|cut -d . -f 2`
#     declare -l url=${title}
#     newline=$(echo ${line}| cut -d : -f 2)
#     declare -i num=$(echo ${line}|cut -d : -f 1)
#     res=$(echo "|${newline%%.*}|[$title](https://leetcode.com/problems/${url//' '/'-'}/description/)|[C++](https://github.com/starFalll/LeetCode/blob/master/algorithms/${newline//' '/'%20'})|")
#     num=num+6
#     sed -i ''${num}'i\'"${res}"'' README.md
# done

###1
#! /bin/bash
#针对之前从未整理过的文件进行整理，请根据自己的目录结构修改
num_i=0
echo "# linux api" >>README.md 
echo " " >>README.md 
echo "| #    |                  Title                   |                                 Solution |" >>README.md 
echo "| :--- | :--------------------------------------: | ---------------------------------------: |" >>README.md 
ls docs|sort -n|while read line #遍历文件夹
do
    title=`echo ${line}|cut -d . -f 2`
    declare -l url=${title}
    echo "|${num_i}|[${line%%.*}](https://github.com/kuanghl/khl_project/tree/master/notes/linux-note/linux-api/docs/${line%%.*}.$title)|[C](https://github.com/kuanghl/khl_project/tree/master/notes/linux-note/linux-api/docs/${line%%.*}.$title)|" >>README.md 
    let num_i+=1
done