#!/bin/bash

if [[ -f icpc_problem.zip ]]; then
  rm icpc_problem.zip
fi
(cd icpc && zip -r ../icpc_problem.zip ./*)