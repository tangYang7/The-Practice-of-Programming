all:
	g++  -c robot.cpp
	g++  -c maze.cpp
	g++  main.cpp robot.o maze.o -o main
	g++ all_in_one.cpp -o test

clean:
	rm -rf *.o main test