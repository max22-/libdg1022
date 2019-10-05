all: lib/libdg1022.so
.PHONY: clean install uninstall

lib/libdg1022.so: lib/libdg1022.o
	gcc -shared lib/libdg1022.o -o lib/libdg1022.so

lib/libdg1022.o: include/DG1022.h src/DG1022.cpp
	gcc -c -fPIC -Iinclude -Wall src/DG1022.cpp -o lib/libdg1022.o

install: lib/libdg1022.so
	cp lib/libdg1022.so /usr/lib

uninstall:
	rm /usr/lib/libdg1022.so

clean:
	rm -f lib/*
