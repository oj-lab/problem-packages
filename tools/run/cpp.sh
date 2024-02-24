#!/bin/bash

SourcePath=$1
InputsFolder=$2

# Compile the source file
SourceFolder=$(dirname "$SourcePath")
TargetName=$(basename "$SourcePath" .cpp).out
g++ -std=c++11 -DUSE_STDIN=1 -o "$SourceFolder"/"$TargetName" "$SourcePath"

# Scan the inputs folder for input files
for InputPath in "$InputsFolder"/*; do
    # Match file ends with .in
    if [[ "$InputPath" != *.in ]]; then
        continue
    fi
    # Run the compiled source file with each input file
    InputName=$(basename "$InputPath" .in)
    OutputPath="$InputsFolder"/"$InputName".ans
    ./"$SourceFolder"/"$TargetName" <"$InputPath" >"$OutputPath"
done
