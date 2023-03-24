all:
	g++  -c robot.cpp
	g++  -c maze.cpp
	g++  main.cpp robot.o maze.o -o main
	g++ test.cpp -o test

clean:
	rm -rf *.o main test