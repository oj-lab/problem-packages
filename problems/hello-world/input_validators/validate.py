#!/usr/bin/env python3
from sys import stdin, exit

data = stdin.read()

# Check for empty file
if not data.strip():
    exit(1)

# Check for binary data
if any(ord(char) > 127 for char in data):
    exit(1)

# Check for random junk at the end of the file
if not data.strip().isprintable():
    exit(1)

# Check for files with only ASCII characters (32 to 127)
if all(32 <= ord(char) <= 127 for char in data):
    exit(1)

# Check for files with extra spaces or newlines
if '  ' in data or '\n\n' in data:
    exit(1)

exit(42)