TARGET: application
fld = object

dll.o:dll.c
	gcc -c dll.c -o dll.o

dll_util.o:dll_util.c
	gcc -c dll_util.c -o dll_util.o

# Those two guys will be used to create the an static library
libdll.a: dll.o dll_util.o
	ar rs libdll.a dll.o dll_util.o

application: application.o libdll.a
	gcc application.o -o application -L libdll.a

application.o:application.c
	gcc -c application.c -o application.o

clean:
	rm dll.o
	rm dll_util.o	
	rm application.o
	rm libdll.a
	rm application
