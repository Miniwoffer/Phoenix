#!/bin/bash
BLUE="\x1b[32m"
RESET="\x1b[0m"
printf "$BLUE\n-------Removing existing build dir-------$RESET\n"
rm -r build