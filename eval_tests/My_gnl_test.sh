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
	./My_Gnl_test.sh middle
	./My_Gnl_test.sh advanced
	./My_Gnl_test.sh 42
	exit 1
fi

if [ $1 = 'basic' ] || [ $1 = 'basic++' ]; then

	printf "${bleu}--------------------------------------------------------------------------------${neutre}\n"
	printf "${bleu}-------------------------------------------------------------------   BASIC TEST${neutre}\n"

	BUFF_SIZE=8

	printf "${orange}BUFF_SIZE="
	printf $BUFF_SIZE
	printf "${neutre}\n\n"

	gcc -Wall -Wextra -Werror -g -I ../libft/includes -I ../ -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
	gcc -Wall -Wextra -Werror -g -I ../libft/includes -I ../ -o basics_test.o -c basics.test.c
	gcc -o basic_test basics_test.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft

	if [ $1 = 'basic++' ]; then
		./basic_test 1
		exit 1 
	else
		./basic_test
		exit 1
	fi

	printf "\n${bleu}**************************************************************************************\n"
	exit 1
fi

if [ $1 = 'middle' ] || [ $1 = 'middle++' ]; then

	printf "${bleu}--------------------------------------------------------------------------------${neutre}\n"
	printf "${bleu}-------------------------------------------------------------------  MIDDLE TEST${neutre}\n"

	BUFF_SIZE=16

	printf "${orange}BUFF_SIZE="
	printf $BUFF_SIZE
	printf "${neutre}\n\n"

	gcc -Wall -Wextra -Werror -g -I ../libft/includes -I ../ -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
	gcc -Wall -Wextra -Werror -g -I ../libft/includes -I ../ -o middle.test.o -c middle.test.c
	gcc -o middle_test middle.test.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft

	if [ $1 = 'middle++' ]; then
		./middle_test 1
		exit 1
	else
		./middle_test
		exit 1
	fi

	printf "\n${bleu}**************************************************************************************\n"
	exit 1
fi

if [ $1 = 'advanced' ] || [ $1 = 'advanced++' ]; then

	printf "${bleu}--------------------------------------------------------------------------------${neutre}\n"
	printf "${bleu}------------------------------------------------------------------ ADVANCED TEST${neutre}\n"

	BUFF_SIZE=4

	printf "${orange}BUFF_SIZE="
	printf $BUFF_SIZE
	printf "${neutre}\n\n"

	gcc -Wall -Wextra -Werror -g -I ../libft/includes -I ../ -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
	gcc -Wall -Wextra -Werror -g -I ../libft/includes -I ../ -o advanced_test.o -c advanced.test.c
	gcc -o advanced_test advanced_test.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft

	if [ $1 = 'advanced++' ]; then
		./advanced_test 1
		exit 1
	else
		./advanced_test
		exit 1
	fi

	printf "\n${bleu}**************************************************************************************\n"
	exit 1
fi

if [ $1 = '42' ] || [ $1 = '42++' ]; then

	printf "${bleu}--------------------------------------------------------------------------------${neutre}\n"
	printf "${bleu}-----------------------------------------------------------------   FD = 42 TEST${neutre}\n"

	BUFF_SIZE=4

	printf "${orange}BUFF_SIZE="
	printf $BUFF_SIZE
	printf "${neutre}\n\n"

	gcc -Wall -Wextra -Werror -g -I ../libft/includes -I ../ -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
	gcc -Wall -Wextra -Werror -g -I ../libft/includes -I ../ -o fd_42.o -c fd42.test.c
	gcc -o fd_42 fd_42.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft

	if [ $1 = '42++' ]; then
		./fd_42 1
		exit 1
	else
		./fd_42
		exit 1
	fi

	printf "\n${bleu}**************************************************************************************\n"
	exit 1
fi