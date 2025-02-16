# Problem Packages

A collection of problem packages which can be directly imported into OJ Lab site.

## Generate Answers

Generate `.ans` with answer source and folder with `.in` files.

```sh
# $1: answer source file
# $2: input folder
./tools/run/cpp.sh problems/nth-element/submissions/accepted/use_std.cpp problems/nth-element/data/secret
```

## Package Format

OJ Lab use a slightly different package format similiar with
[Kattis/problem-package-format](https://github.com/Kattis/problem-package-format),
but support fewer fields & features currently.

### Main difference

1. OJ Lab only support Markdown format for problem statement.
2. In `problem.yaml` OJ Lab use an extra field: `oj-lab-metadata` to store the configuration for the OJ Lab platform.

## Validate Package

The packages can be validated by
[Kattis/problemtools](https://github.com/Kattis/problemtools).

```sh
docker pull problemtools/icpc
docker run --rm -v ./problems:/problems problemtools/icpc verifyproblem ./problems/hello-world
```

This can mainly help you by quickly validate your test data and submission files.

### Note

Since OJ Lab use a slightly different package format,
you will need to ignore some of the error & warning like:

```text
ERROR in hello-world: Invalid shortname 'hello-world' (must be [a-z0-9]+)
WARNING in problem configuration: Unknown field 'oj-lab-metadata' provided in problem.yaml
ERROR in problem statement: No problem statements found (expected problem.tex or problem.[a-z][a-z].tex in problem_statement directory)
```

**For problem statement, make sure you have at least one of `problem.en.md` or `problem.md` in the package.**
