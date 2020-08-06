CC=clang

all: duct holepuncher

duct: duct.c

holepuncher: holepuncher.c

clean:
	rm -f duct *.o

install:
	echo "install"

uninstall:
	echo "uninstall"

test: all
	./duct
	./duct send
	./duct listen
	./duct flow
	./duct aoeu

.PHONY: all clean install uninstall
