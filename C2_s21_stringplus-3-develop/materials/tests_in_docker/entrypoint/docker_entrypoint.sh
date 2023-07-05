#!/usr/bin/env bash

mkdir -p logs
# perform make with target "test", write your own target here
make test 2>&1 | tee "logs/test_make_$(date +"%d_%m_%y__%H_%M_%S").log"

# VALGRIND checks compiled program for leaks, saving it to logfile
# 2>&1 | tee construction copy stdout and stderr to file, instead of just redirecting
echo -e "\\e[94m\\e[40m Do you want to test your project with valgrind? This can take a long time.\n [Yy/...]\\e[0m"
read -r answer
if [[ "$answer" = [Yy]* ]]; then
  valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test 2>&1 | tee "logs/test_valgrind_$(date +"%d_%m_%y__%H_%M_%S").log"
fi


# CLANG-FORMAT  compiled program style based on .clang-format file, copied to src, or from
# /entrypoint/common/.clang-format if there is no one in src
# to apply clang format use -i flag instead
if [ ! -d .clang-format ]; then
  cp ../entrypoint/common/.clang-format .clang-format
fi
clang-format -n *.c *.h tests/*.c tests/*.h 2>&1 | tee "logs/test_clang_$(date +"%d_%m_%y__%H_%M_%S").log"


# CPPLINT checks compiled program with cpp linter, based on .cfg file, stored in /common folder
cp ../entrypoint/common/CPPLINT.cfg CPPLINT.cfg
cpplint *.c *.h tests/*.c tests/*.h 2>&1 | tee "logs/test_cpplint_$(date +"%d_%m_%y__%H_%M_%S").log"


# CPPCHECK static code analyzer. "-q --enable=all --inconclusive" for maximum sensitivity
cppcheck -q --enable=all --inconclusive *.c *.h tests/*.c tests/*.h 2>&1 | tee "logs/test_cppcheck_$(date +"%d_%m_%y__%H_%M_%S").log"


echo -e "\\e[94m\\e[40m Do you want to finish working with container and exit?[Yy/...]\\e[0m"
read -r answer
if [[ "$answer" = [Yy]* || "$answer" = "exit" ]]; then
  exit
else
  echo -e "\\e[94m\\e[40m Print <exit> at any time you want to finish working with container.\\e[0m"
fi

make clean

# To open interactive window with TTY to container terminal, otherwise container stops right after finishing script.
# Prompt "exit" to exit interactive mode and stop container.
/bin/bash