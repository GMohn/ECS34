
CXX			= g++
TESTLDFLAGS	+= -lgtest -lgtest_main -lpthread
CXXFLAGS	= -std=c++17 -Wall -Werror

#DEBUG_MODE=TRUE
ifdef DEBUG_MODE
DEFINES  += -DDEBUG
CFLAGS   += -g -ggdb -D_GLIBCXX_DEBUG
else 
CFLAGS   += -O3
endif

bin/proj3: obj/main.o obj/SixMensMorrisBoard.o obj
	$(CXX) obj/main.o obj/SixMensMorrisBoard.o -o bin/proj3 

obj/main.o: srv/main.o
	$(CXX) -c str/main.cpp -o obj/main.o

obj/SixMensMorrisBoard.o: src/SixMensMorrisBoard.cpp include/SixMensMorrisBoard.h
	$(CXX) -c src/SixMensMorrisBoard.cpp -o obj/SixMensMorrisBoard.o
clean:
	rm .o proj3