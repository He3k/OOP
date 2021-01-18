all: bin/main

bin/main: obj/main.o
	g++ -Wall -Werror obj/main.o -o bin/main
obj/main.o: src/main.cpp
	g++ -I include -c src/main.cpp -o obj/main.o

run:
	bin/./main

clear:
	rm -rf bin/main
	rm -rf obj/*.o
