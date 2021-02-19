Summary

The aim of this project is to make a function that returns a line ending with a newline, read from a file discriptor.

Desciption

get_next_line project you finally be able to write a function that will allow you to read a line ending with a newline character froma file discriptor. You will be able to add this function tou the libft if you feel like it and use it if required so.

Running the program (From terminal)

git clone --recursive https://github.com/lmolaodi/get_next_line.git
cd to project folder
make -C libft/ fclean && make -C libft/
gcc -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
gcc -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
gcc -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

