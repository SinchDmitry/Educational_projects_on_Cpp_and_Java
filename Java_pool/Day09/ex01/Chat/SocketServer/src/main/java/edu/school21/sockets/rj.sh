#!/bin/bash
if grep -q "package" "Program.java"; then
	printf "\33c\e[3J" && javac -d . ./*/*.java && java $(basename $(pwd)).Program $1
else
	printf "\33c\e[3J" && javac -d . ./*/*.java && java Program $1
fi
rm -rf *.class
