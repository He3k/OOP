all: bin/main

bin/main: obj/main.o obj/tree.o
	g++ -Wall -Werror obj/main.o obj/tree.o -o bin/main

obj/main.o: src/main.cpp include/tree.h
	g++ -I include -c src/main.cpp -o obj/main.o

obj/tree.o: src/tree.cpp include/tree.h
	g++ -I include -c src/tree.cpp -o obj/tree.o

run:
	bin/./main

clear:
	rm -rf bin/main obj/*.o
