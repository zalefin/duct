CC=clang

all: duct registrar

duct:
	clang duct.c -o duct

registrar: registrar.c

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
