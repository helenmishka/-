app.exe: a.o main.o
	gcc -Wall -Werror -o app.exe a.o main.o
	./app.exe
a.o: a.c
	gcc -Wall -Werror -c a.c -o a.o
main.o: main.c
	gcc -Wall -Werror -c main.c -o main.o
clean: 
	rm *.o *.exe