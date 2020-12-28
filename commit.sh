#!/bin/sh
# BOJ : ./commit.sh boj "$2" "$3"
# Programmers : ./commit.sh programmers "$2"

message=""
flag=0

boj() {
    message="BOJ_$1.$2"
}

programmers() {
    message="Programmers.$1"
}

if [ "$1" = "boj" ]
then
    if [ "$2" = "" ] || [ "$3" = "" ]
    then
        message="error: must have 2 args"
    else
        boj "$2" "$3"
        flag=1
    fi
elif [ "$1" = "programmers" ]
then
    if [ "$2" = "" ]
    then
        message="error: must have 1 args"
    else
        programmers "$2"
        flag=1
    fi
else
    message="error: none type (boj, programmers)"
fi

if [ $flag -eq 0 ]
then
    echo "$message"
    exit 2
else
    git add .
    git commit -m "$message"
    git push -u origin master
fi