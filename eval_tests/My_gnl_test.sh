#!/bin/bash

bleu='\e[1;34m'
orange='\e[0;33m'


neutre='\e[0;m'

if [ $1 = 'clean' ]; then
	rm -f *.o
	rm -f ../get_nextline.o
	rm -f basic_test fd_0 fd_42 test_gnl middle_test
	exit 1
fi

if [ $1 = 'make' ]; then
	make -C ../libft/ fclean && make -C ../libft/
	exit 1
fi

if [ $1 = 'all' ]; then
	./My_gnl_test.sh basic
	./My_gnl_test.sh middle
	./My_gnl_test.sh advanced
	./My_gnl_test.sh 42
	./My_gnl_test.sh stdout
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

	printf "${bleu}**************************************************************************************\n"
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

	printf "${bleu}**************************************************************************************\n"
	exit 1
fi

if [ $1 = 'stdout' ] || [ $1 = 'stdout++' ]; then
	printf "${bleu}---------------------------------------------------------------------------------------\n${neutre}"
	printf "${bleu}--------------------------------------------------------------------   READ FROM STDOUT\n${neutre}"
	 BUFF_SIZE=8
	 printf "${orange}BUFF_SIZE = "
	 printf ${BUFF_SIZE}
	 printf "${neutre}\n\n"

	gcc -Wall -Wextra -Werror -g -I ../libft/includes -I ../ -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
	gcc -Wall -Wextra -Werror -g -I ../libft/includes -I ../ -o fd0.test.o -c fd0.test.c
	gcc -o fd_0 fd0.test.o ../get_next_line.o -L ../libft/ -lft

	if [ $1 = 'stdout++' ]; then
		 cat ./TestFiles/basictest8c1L.txt | ./fd_0 1 8 1
		 cat ./TestFiles/basictest8c2L.txt | ./fd_0 2 8 1
		 cat ./TestFiles/basictest8cxL.txt | ./fd_0 3 8 1
	else
		cat ./TestFiles/basictest8c1L.txt | ./fd_0 1 8
		cat ./TestFiles/basictest8c2L.txt | ./fd_0 2 8
		cat ./TestFiles/basictest8cxL.txt | ./fd_0 3 8
	fi

	BUFF_SIZE=16
	printf "${orange}BUFF_SIZE = "
	printf $BUFF_SIZE
	printf "${neutre}\n\n"
	gcc -Wall -Werror -Wextra -g -I ../libft/includes -I ../ -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
	gcc -Wall -Werror -Wextra -g -I ../libft/includes -I ../ -o fd0.test.o -c fd0.test.c
	gcc -o fd_0 fd0.test.o ../get_next_line.o -L ../libft/ -lft

	if [ $1 = 'stdout++' ]; then
		cat ./TestFiles/middletest16c1L.txt | ./fd_0 1 16 1
		cat ./TestFiles/middletest16c2L.txt | ./fd_0 2 16 1
		cat ./TestFiles/middletest16cxL.txt | ./fd_0 3 16 1
	else
		cat ./TestFiles/middletest16c1L.txt | ./fd_0 1 16
		cat ./TestFiles/middletest16c2L.txt | ./fd_0 2 16
		cat ./TestFiles/middletest16cxL.txt | ./fd_0 3 16
	fi

	BUFF_SIZE=4
	printf "${orange}BUFF_SIZE = "
	printf $BUFF_SIZE
	printf "${neutre}\n\n"
	gcc -Wall -Werror -Wextra -g -I ../libft/includes -I../ -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
	gcc -Werror -Wextra -Wall -g -I ../libft/includes -I ../ -o fd0.test.o -c fd0.test.c
	gcc -o fd_0 fd0.test.o ../get_next_line.o -L ../libft/ -lft

	if [ $1 = 'stdout++' ]; then
		cat ./TestFiles/advancedtest4c1L.txt | ./fd_0 1 4 1
		cat ./TestFiles/advancedtest4c2L.txt | ./fd_0 2 4 1
		cat ./TestFiles/advancedtest4cxL.txt | ./fd_0 3 4 1
		exit 1
	else
		cat ./TestFiles/advancedtest4c1L.txt | ./fd_0 1 4
		cat ./TestFiles/advancedtest4c2L.txt | ./fd_0 2 4
		cat ./TestFiles/advancedtest4cxL.txt | ./fd_0 3 4
		exit 1
	fi
fi