#!/bin/bash

bleu='\e[1;34m'
orange='\e[0;33m'


neutre='\e[0;m'

if [ $1 = 'clean' ]; then
	rm -f *.o
	rm -f ../get_nextline.o
	exit 1
fi

if [ $1 = 'make' ]; then
	make -C ../libft/ fclean && make -C ../libft/
	exit 1
fi

if [ $1 = 'all' ]; then
	./My_gnl_test.sh basic
#	./My_Gnl_test.sh 2
#	./My_Gnl_test.sh 3
#	./My_Gnl_test.sh 4
	exit 1
fi

if [ $1 = 'basic' ] || [ $1 = 'basic ++' ]; then

printf "${bleu}--------------------------------------------------------------------------------${neutre}\n"
printf "${bleu}-------------------------------------------------------------------   BASIC TEST${neutre}\n"

BUFF_SIZE=8

printf "${orange}BUFF_SIZE="
printf $BUFF_SIZE
printf "${neutre}\n\n"

gcc -Wall -Wextra -Werror -g -I ../libft/includes -I ../ -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
gcc -Wall -Wextra -Werror -g -I ../libft/includes -I ../ -o basics_test.o -c basics.test.c
gcc -o basic_test basics_test.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft

if [ $1 = 'basic ++' ]; then
	./basic_test 1
	exit 1
else
	./basic_test
	exit 1
fi

printf "\n${bleu}**************************************************************************************\n"
fi