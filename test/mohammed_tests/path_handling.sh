#!/bin/bash

# test that our simple shell can execute commands just using its name
# no need to give it the absolute paths of the executable files of the commands
echo "ls -a -l" | ../../hsh
echo "pwd" | ../../hsh
echo "whoami" | ../../hsh
