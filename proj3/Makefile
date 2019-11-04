output: main.o SixMensMorrisBoard.o
	g++ main.o SixMensMorrisBoard -o output

main.o: main.cpp
	g++ -c main.cpp

SixMensMorrisBoard.o: SixMensMorrisBoard.cpp SixMensMorrisBoard.h
	g++ -c SixMensMorrisBoard.cpp

clean:
	rm *.o output