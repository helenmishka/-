ftest: static sprog dynamic dprog lprog
	./test.sh
static: darray_lib.c
	gcc -std=c99 -Wall -Werror -c darray_lib.c
	ar rc libdarray.a darray_lib.o
	ranlib libdarray.a
sprog: lab08.c static
	gcc -std=c99 -Wall -Werror lab08.c -L. -ldarray -o app_s.exe
	
dynamic: darray_lib.c
	gcc -std=c99 -Wall -Werror -c darray_lib.c
	gcc -shared darray_lib.o -Wl,--subsystem,windows -o darray.dll
dprog: lab08.c dynamic
	gcc -std=c99 -Wall -Werror -c lab08.c
	gcc lab08.o -L. -ldarray -o app_d.exe
	
lprog: lab08_d.c dynamic
	gcc -std=c99 -Wall -Werror lab08_d.c -o app_l.exe
clean:
	rm *.exe *.o *.dll *.a
