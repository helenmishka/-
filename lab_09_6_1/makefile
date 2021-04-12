# Компилятор
CC = gcc

# Опции компиляции
CFLAGS = -std=c99 -Wall -Werror
all: app.exe test.exe

app.exe: lab09.o dmatrix.o memory.o input_output.o
	$(CC) -o $@ $^
test.exe: test.o dmatrix.o memory.o input_output.o change_matrix_del_test.o change_matrix_add_test.o pow_matrix_test.o multiplication_matrix_test.o
	$(CC) $(CFLAGS) -o $@ $^
lab09.o: lab09.c
	$(CC) $(CFLAGS) -c $^ -o $@
dmatrix.o: dmatrix.c
	$(CC) $(CFLAGS) -c $^ -o $@
memory.o: memory.c
	$(CC) $(CFLAGS) -c $^ -o $@
input_output.o: input_output.c
	$(CC) $(CFLAGS) -c $^ -o $@
test.o: test.c
	$(CC) $(CFLAGS) -c $^ -o $@
change_matrix_del_test.o: change_matrix_del_test.c
	$(CC) $(CFLAGS) -c $^ -o $@
change_matrix_add_test.o: change_matrix_add_test.c
	$(CC) $(CFLAGS) -c $^ -o $@
pow_matrix_test.o: pow_matrix_test.c
	$(CC) $(CFLAGS) -c $^ -o $@
multiplication_matrix_test.o: multiplication_matrix_test.c
	$(CC) $(CFLAGS) -c $^ -o $@
clean:
	rm *.o *.exe
	