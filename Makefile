all: lib/libdg1022.so examples
.PHONY: clean install uninstall examples

lib/libdg1022.so: lib/libdg1022.o lib/devicestream.o
	gcc -shared lib/devicestream.o lib/libdg1022.o -o lib/libdg1022.so

lib/libdg1022.o: include/DG1022.h src/DG1022.cpp
	gcc -c -fPIC -Iinclude -I src -Wall src/DG1022.cpp -o lib/libdg1022.o

lib/devicestream.o: src/devicestream.h src/devicestream.cpp
	gcc -c -fPIC -Isrc -Wall src/devicestream.cpp -o lib/devicestream.o

examples: lib/libdg1022.so
	$(MAKE) -C examples

install: lib/libdg1022.so
	cp lib/libdg1022.so /usr/lib

uninstall:
	rm -f /usr/lib/libdg1022.so

clean:
	rm -f lib/*
	$(MAKE) -C examples clean
