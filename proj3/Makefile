
CXX=g++
CXXFLAGS = -std=c++14 -Wall -Werror

#DEBUG_MODE=TRUE
ifdef DEBUG_MODE
DEFINES  += -DDEBUG
CFLAGS   += -g -ggdb -D_GLIBCXX_DEBUG
else 
CFLAGS   += -O3
endif

bin/proj3: obj/main.o obj/SixMensMorrisBoard.o obj$(CXX) obj/main.o 

clean:
	rm .o proj3