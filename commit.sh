#!/bin/sh
# BOJ : ./commit.sh b "$2" "$3"
# Programmers : ./commit.sh p "$2"

date=$(date '+%y_%m_%d')
message=""
flag=0

boj() {
    message="BOJ_$1_$date"
}

programmers() {
    message="PROGMS_$1($2)_$date"
}

if [ "$1" = "b" ]
then
    if [ "$2" = "" ]
    then
        message="usage: ./commit.sh b <problem_name>"
    else
        boj "$2"
        flag=1
    fi
elif [ "$1" = "p" ]
then
    if [ "$2" = "" ] || [ "$3" = "" ]
    then
        message="usage: ./commit.sh p <problem_name> <extension>"
    else
        programmers "$2" "$3"
        flag=1
    fi
else
    message="usage: ./commit.sh <b|p> <problem_name> [<extension>]"
fi

if [ $flag -eq 0 ]
then
    # print error message with red color
    echo "\033[31m$message\033[0m"
    exit 1
else
    git add .
    git commit -m "$message"
    echo "Successfully committed with message: $message"
    exit 0
fi
