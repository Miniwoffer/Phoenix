#!/bin/bash
BLUE="\x1b[32m"
RESET="\x1b[0m"
printf "$BLUE\n-------Removing existing build dir-------\n"
rm -r build
printf "\n-----------Making build folder-----------\n"
mkdir build
printf "\n-----------Moving to build dir-----------\n"
cd build
printf "\n--------Running cmake from build---------$RESET\n"
cmake ../Phoenix
printf "$BLUE\n-------------Running makefile------------\n"
make
printf "$BLUE\n---------Copying content-----------$RESET\n"
cp -r -v ../Phoenix/GamePlayground/Fonts Fonts/
cp -r -v ../Phoenix/GamePlayground/Images Images/
cp -r -v ../Phoenix/GamePlayground/Levels Levels/
printf "$BLUE\n----------Exectuing Playground----------$RESET\n"
./phoenix