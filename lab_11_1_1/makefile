# Компилятор
CC = gcc

# Опции компиляции
CFLAGS = -std=c99 -Wall -Werror

all: test.exe

utest: test.exe
	./test.exe
    
test.exe: test.o lab11.o
	$(CC) $(CFLAGS) -o $@ $^
lab11.o: lab11.c
	$(CC) $(CFLAGS) -c $^ -o $@
test.o: test.c
	$(CC) $(CFLAGS) -c $^ -o $@
clean:
	rm *.o *.exe
	