#!/bin/bash
if [[ $# -ne 2 ]]; then
  echo "usage: ./addProblem.sh problem_name sample_count"
  exit 1
fi

name=$1
count=$2

base=icpc/$name
mkdir -p $base


mkdir -p $base/data/sample
for ((i=0; i<count; i++))
do
  touch $base/data/sample/"${i}.in"
  touch $base/data/sample/"${i}.ans"
done

mkdir -p $base/data/secret


mkdir $base/problem_statement
touch $base/problem_statement/problem.md


mkdir -p $base/submissions/accepted
touch $base/submissions/accepted/use_std.cpp
touch $base/problem.yaml