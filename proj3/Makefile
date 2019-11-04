CXX = g++
TESTLDFLAGS += -lgtest -lgtest_man -lpthread
CXXFLAGS  = -std=c++14 -Wall -Werror


TESTBIN_DIR = ./testbin

bin/proj3: obj/main.o obj/SixMensMorrisBoard.o obj
	$(CXX) obj/main.o obj/SixMensMorrisBoard.o -o bin/proj3

obj/main.o: src/main.cpp include/SixMensMorrisBoard.h
	$(CXX) -c src/main.cpp -o obj/main.o

obj/SixMensMorrisBoard.o: src/SixMensMorrisBoard.cpp include/SixMensMorrisBoard.h
	$(CXX) -c src/SixMensMorrisBoard.cpp -o obj/SixMensMorrisBoard.o

clean:
	rm .o proj3