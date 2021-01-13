all:main

main:src/course.cpp
	g++ src/course.cpp -o bin/main
run:
	bin/./main

clean:
	rm  bin/main
	
checkdir:
	mkdir -p bin
