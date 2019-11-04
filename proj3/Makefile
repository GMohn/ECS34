CXX = g++
TESTLDFLAGS += -lgtest -lgtest_man -lpthread
CXXFLAGS  = -std=c++14 -Wall -Werror



bin/proj3: main.o SixMensMorrisBoard.o obj
	$(CXX) main.o SixMensMorrisBoard.o -o proj3

obj/main.o: main.cpp SixMensMorrisBoard.h
	$(CXX) -c main.cpp -o main.o

obj/SixMensMorrisBoard.o: SixMensMorrisBoard.cpp SixMensMorrisBoard.h
	$(CXX) -c SixMensMorrisBoard.cpp -o SixMensMorrisBoard.o

clean:
	rm .o proj3