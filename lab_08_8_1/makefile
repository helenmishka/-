app.exe: lab08.o darray.o test.exe
	gcc -Wall -Werror -o app.exe lab08.o darray.o
test.exe: test.o darray.o
	gcc -Wall -Werror -o test.exe test.o darray.o
lab08.o: lab08.c
	gcc -Wall -Werror -c lab08.c -o lab08.o
darray.o: darray.c
	gcc -Wall -Werror -c darray.c -o darray.o
test.o: test.c
	gcc -Wall -Werror -c test.c -o test.o
