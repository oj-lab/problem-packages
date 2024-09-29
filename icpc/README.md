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

### Additional Information

There are some differences between the ICPC format and the real usage in the OJ Lab:

In `problem.yaml`, there is an additional field `oj_lab_config`
which is used to store the configuration for the OJ Lab platform.
You can add the additional information in this format:

```yaml
oj_lab_config:
  difficulty: "easy"
  tags:
    - "strings"
    - "input-output"
```

These fields can help fullfill the problem information for the OJ Lab.
