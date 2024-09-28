#!/bin/bash

if [[ $# -ne 1 ]]; then
  echo "usage: ./rename.sh DIRECTORY"
  echo "01  01.a  -> 01.in  01.ans"
  exit 1
fi

DIRECTORY="$1"

echo $DIRECTORY
for FILE in "$DIRECTORY"/*; do
    BASENAME=$(basename "$FILE")
    echo $BASENAME

    if [[ -f "$FILE" ]]; then
        if [[ "$BASENAME" =~ ^([0-9]+)$ ]]; then
            # 修改后缀为.in
            mv "$FILE" "$DIRECTORY/${BASENAME}.in"
        elif [[ "$BASENAME" =~ ^([0-9]+)\.a$ ]]; then
            # 修改后缀为.ans
            mv "$FILE" "$DIRECTORY/${BASENAME%.a}.ans"
        fi
    fi
done

echo "rename finished!"