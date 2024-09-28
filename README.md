# problem-packages

A collection of problem packages which can be easily migrate from other public platform (Ex. LeetCode) and migration tools.

## Pre-requisite

To enable C++ debugging, you need to install `gdb` package.

```sh
# For example, on Ubuntu
sudo apt-get install gdb
```

You may also need a Node.js environment to run the description-migration / input-convertion tool. Run `npm install` to install the dependencies.

## Usage

Generate `.ans` with answer source and folder with `.in` files.

```sh
# $1: answer source file
# $2: input folder
./tools/run/cpp.sh icpc/nth-element/submissions/accepted/use_std.cpp icpc/nth-element/data/secret
```
