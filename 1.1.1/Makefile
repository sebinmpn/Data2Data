CC=g++

CFLAGS+=-std=c++17
CFLAGS+=-Wall
LIB=-lfltk
d2d:d2d.cxx
	$(CC) $(CFLAGS) d2d.cxx -o d2d

list:list.cxx
	$(CC) $(CFLAGS) list.cxx -o list

name:name.cxx
	$(CC) $(CFLAGS) name.cxx -o name

window:window.cxx
	$(CC) $(CFLAGS) window.cxx $(LIB) -o window
	


clean:
	rm -rf d2d
