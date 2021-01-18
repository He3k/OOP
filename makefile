all:main

main:src/course.cpp
	g++ src/main.cpp -o bin/main
run:
	bin/./main

clean:
	rm  bin/main
	
checkdir:
	mkdir -p bin
