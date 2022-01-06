#!/bin/bash
rm -f ../get_next_line.o main.o
rm -f test_gnl
make -C ../libft/ fclean && make -C ../libft/
gcc -g -Wall -Wextra -Werror -I ../libft/includes -I ../ -o ../get_next_line.o -c ../get_next_line.c
gcc -g -Wall -Wextra -Werror -I ../libft/includes -I ../ -o main.o -c main.c
gcc -g -o test_gnl main.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft
rm -f ../get_next_line.o

echo "*----------------------*"
echo "*----- BASIC TEST -----*"
echo "*----------------------*"
echo ""
echo "*----------------------*"
echo "READ FROM STDOUT ------*"
echo "*----------------------*"
echo ""
echo "8 chacaracter·1L:"
cat basictest8c1L.txt | ./test_gnl

echo "*----------------------*"
echo "8 Character 2L"
cat basictest8c2L.txt | ./test_gnl

echo "*----------------------*"
echo "8 Characters X L"
cat basictest8cxL.txt | ./test_gnl

echo "*----------------------*"
echo "READ FROM A FILE ------*"
echo "*----------------------*"
echo "8 chacaracter 1L:"
./test_gnl basictest8c1L.txt

echo "*----------------------*"
echo "8 Charactere 2L:"
./test_gnl basictest8c2L.txt

echo "*----------------------*"
echo "8 Charactere X L:"
./test_gnl basictest8cxL.txt

echo "*----------------------*"
echo "*----- MIDDLE TEST ----*"
echo "*----------------------*"
echo ""
echo "*----------------------*"
echo "READ·FROM·STDOUT·------*"
echo "*----------------------*"
echo "16·chacaracter·1L:"
cat middletest16c1L.txt | ./test_gnl

echo "*----------------------*"
echo "16·chacaracter·2L:"
cat middletest16c2L.txt | ./test_gnl

echo "*----------------------*"
echo "16·chacaracter· x L:"
cat middletest16cxL.txt | ./test_gnl

echo "*----------------------*"
echo "READ·FROM·A·FILE·------*"
echo "*----------------------*"
echo "16·chacaracter·1L:"
./test_gnl middletest16c1L.txt

echo "*----------------------*"
echo "16·chacaracter·2L:"
./test_gnl middletest16c2L.txt

echo "*----------------------*"
echo "16·chacaracter· X L:"
./test_gnl middletest16cxL.txt

echo "*----------------------*"
echo "*----·ADVANCED·TEST·---*"
echo "*----------------------*"

echo "*----------------------*"
echo "READ·FROM·STDOUT·------*"
echo "*----------------------*"
echo "4·chacaracter·1L:"
cat advancedtest4c1L.txt | ./test_gnl

echo "*----------------------*"
echo "4·chacaracter·2L:"
cat advancedtest4c2L.txt | ./test_gnl

echo "*----------------------*"
echo "4·chacaracter··x·L:"
cat advancedtest4cxL.txt | ./test_gnl

echo "*----------------------*"
echo "READ·FROM·A·FILE·------*"
echo "*----------------------*"
echo "4·chacaracter·1L:"
./test_gnl advancedtest4c1L.txt

echo "*----------------------*"
echo "4·chacaracter·2L:"
./test_gnl advancedtest4c2L.txt

echo "*----------------------*"
echo "4·chacaracter··X·L:"
./test_gnl advancedtest4cxL.txt

echo "*----------------------*"
echo "empty line:"
./test_gnl advancedtestemptyline.txt

echo "*----------------------*"
echo "4, 8 and 16 Charactere without \\n"
./test_gnl advancedtest4cnoNL.txt
./test_gnl advancedtest8cnoNL.txt
./test_gnl advancedtest16cnoNL.txt

echo "*------------------------*"
echo "BIG FAT LINE"
./test_gnl Bigfatline.txt

echo "*-------------------------*"
echo "MUTIPLE FILE DESCRIPTOR"
./test_gnl fd1.txt fd2.txt fd3.txt fd4.txt fd5.txt

echo "*-------------------------*"
echo "Specific_case"
./test_gnl specific_case.txt

echo "NANO FILE"
./test_gnl nano_file.txt

echo "TEST NOEOL"
./test_gnl noeolfile.txt
