CC=g++

CFLAGS+=-std=c++17
CFLAGS+=-Wall
LIB=-lfltk

d2d:d2d.cxx
	$(CC) $(CFLAGS) d2d.cxx $(LIB) -o d2d

list:main.cxx
	$(CC) $(CFLAGS) main.cxx $(LIB) -o main	

name:name.cxx
	$(CC) $(CFLAGS) name.cxx -o name

file:file.cxx
	$(CC) $(CFLAGS) file.cxx $(LIB) -o file
	
formobj:form.o
	$(CC) $(CFLAGS) -c form.cxx	
libform:libform.a
	ar rcs  libform.a form.o 


clean:
	rm -rf d2d
