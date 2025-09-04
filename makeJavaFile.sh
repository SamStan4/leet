#!/usr/bin/env bash

readonly EASY="easy"
readonly MEDIUM="medium"
readonly HARD="hard"
readonly PATH_PREFIX="java_leet/java/src/leetcode/"
readonly SOLUTION_FILE_NAME="/Solution.java"

DIFFICULTY_PATH_PART=""

too_few_command_line_args() {
  echo "err, program takes two command line args"
  exit 1
};

incorrect_difficulty_flag() {
  echo "err, command line arg is one of {-e, -m, -h}"
  exit 1
};

if [ $# -lt 2 ]; then
  too_few_command_line_args
fi

case "$1" in
  -e) DIFFICULTY_PATH_PART=$EASY ;;
  -m) DIFFICULTY_PATH_PART=$MEDIUM ;;
  -h) DIFFICULTY_PATH_PART=$HARD ;;
  *)  incorrect_difficulty_flag ;;
esac

readonly DIR_PATH="$PATH_PREFIX$DIFFICULTY_PATH_PART/$2"
readonly FULL_PATH="$DIR_PATH$SOLUTION_FILE_NAME"

mkdir -p $DIR_PATH
touch "$FULL_PATH"

echo "package leetcode.$DIFFICULTY_PATH_PART.$2;" > $FULL_PATH

echo "created $FULL_PATH"