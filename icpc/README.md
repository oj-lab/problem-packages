# ICPC Format Packages

See more about package format in <https://icpc.io/problem-package-format/>

## Compatibility

For [Judger](https://github.com/oj-lab/judger) and [OJ Lab Platform](https://github.com/oj-lab/platform)
they currently only supports loading the following information:

- In `problem.yaml`
  - `name`: The name of the problem
  - `limit.memory`: The memory limit of the problem
  - `limit.output`: The limit size of the output content
- In `.timelimit`, the value indicates the maximum seconds for each test case
