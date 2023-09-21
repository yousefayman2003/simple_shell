#!/bin/bash

# make sure that my implementation of env command works like built-in env command
# hsh is the name of our executable file of our simple shell
echo -e "\nThe output of my env command:\n"
echo "env" | ../../hsh
echo -e "\n\nThe output of built-in env command:\n"
env
