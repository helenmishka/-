# Компилятор
CC = gcc

# Опции компиляции
CFLAGS = -std=c99 -Wall -Werror -g
all: app.exe test.exe
utest: test.exe
	./test.exe
ftest: app.exe
	./test.sh
app.exe: main.o main_funcs.o list.o input_output.o key_funcs.o
	$(CC) -o $@ $^
test.exe: test.o main_funcs.o list.o input_output.o key_funcs.o
	$(CC) -o $@ $^
main.o: main.c
	$(CC) $(CFLAGS) -c $^ -o $@
main_funcs.o: main_funcs.c
	$(CC) $(CFLAGS) -c $^ -o $@
list.o: list.c
	$(CC) $(CFLAGS) -c $^ -o $@
key_funcs.o: key_funcs.c
	$(CC) $(CFLAGS) -c $^ -o $@
input_output.o: input_output.c
	$(CC) $(CFLAGS) -c $^ -o $@
test.o: test.c
	$(CC) $(CFLAGS) -c $^ -o $@
clean:
	rm *.o *.exe
	
