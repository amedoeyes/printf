#!/bin/bash

command=gcc
flags=(-Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format -ggdb)
files=(./*.c ./tests/*.c ./tests/**/*.c)
out_dir="./build"
executable="printf_test"

if [ ! -d "$out_dir" ]; then
	mkdir "$out_dir"
fi

"$command" "${flags[@]}" "${files[@]}" -o "$out_dir"/"$executable"
