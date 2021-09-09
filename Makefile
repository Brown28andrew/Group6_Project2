prog: main.o Grid.o Output.o
	g++ -std=c++11 -g -Wall main.o Grid.o Output.o -o prog

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Grid.o: Grid.h Grid.cpp
	g++ -std=c++11 -g -Wall -c Grid.cpp

Output.o: Output.h Output.cpp
	g++ -std=c++11 -g -Wall -c Output.cpp

clean: 
	rm *.o prog