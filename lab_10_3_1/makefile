# Компилятор
CC = gcc

# Опции компиляции
CFLAGS = -std=c99 -Wall -Werror -g
all: app.exe test.exe


utest: test.exe
	./test.exe
ftest:
	./test.sh
app.exe: main.o main_funcs.o memory.o input_output.o sort.o utilities.o
	$(CC) -o $@ $^
test.exe: test.o main_funcs.o memory.o input_output.o sort.o utilities.o test_sort.o test_main_funcs.o test_check.o
	$(CC) $(CFLAGS) -o $@ $^
main.o: main.c
	$(CC) $(CFLAGS) -c $^ -o $@
main_funcs.o: main_funcs.c
	$(CC) $(CFLAGS) -c $^ -o $@
memory.o: memory.c
	$(CC) $(CFLAGS) -c $^ -o $@
sort.o: sort.c
	$(CC) $(CFLAGS) -c $^ -o $@
input_output.o: input_output.c
	$(CC) $(CFLAGS) -c $^ -o $@
utilities.o: utilities.c
	$(CC) $(CFLAGS) -c $^ -o $@
test.o: test.c
	$(CC) $(CFLAGS) -c $^ -o $@
clean:
	rm *.o *.exe
	
