all: ctest

# Set CFLAGS to allow Debug and issue all warnings.
CFLAGS = -g -Wall

ctest: ctest.o mystring.o
	gcc $(CFLAGS) ctest.o mystring.o -o ctest

ctest.o: ctest.c mystring.h
	gcc $(CFLAGS) -c ctest.c

mystring.o: mystring.c mystring.h
	gcc $(CFLAGS) -c mystring.c

clean:
	rm -f mystring.o ctest.o ctest
	rm -f -r html latex

docs:
	doxygen
	# Following lines are only needed if we want to access doc pages
	#   using a Web server.
	#chmod go+r html/*
	#cp html/* ~/public_html/cs2303assig3
