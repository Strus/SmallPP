#!/bin/sh
cppcheck --project=cmake/compile_commands.json --enable=all --suppress=missingIncludeSystem
