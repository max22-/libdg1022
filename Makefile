all: lib/libdg1022.so examples
.PHONY: clean install uninstall examples

CFLAGS = -Iinclude

lib/libdg1022.so: lib/libdg1022.o lib/devicestream.o
	gcc -shared lib/devicestream.o lib/libdg1022.o -o lib/libdg1022.so

lib/libdg1022.o: include/DG1022/DG1022.h src/DG1022.cpp include/DG1022/enums.h
	gcc -c -fPIC -Iinclude -Isrc -Wall src/DG1022.cpp -o lib/libdg1022.o

lib/devicestream.o: include/DG1022/devicestream.h src/devicestream.cpp include/DG1022/enums.h
	gcc -c -fPIC -Iinclude -Isrc -Wall src/devicestream.cpp -o lib/devicestream.o

examples: lib/libdg1022.so
	$(MAKE) -C examples

install: lib/libdg1022.so
	cp lib/libdg1022.so /usr/lib
	rm -rf /usr/include/DG1022
	cp -r include/DG1022 /usr/include

uninstall:
	rm -f /usr/lib/libdg1022.so
	rm -rf /usr/include/DG1022/

clean:
	rm -f lib/*
	$(MAKE) -C examples clean
