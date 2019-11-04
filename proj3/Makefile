CXX	= g++
CPP = cpp
LD = ld
OBJCOPY = objcopy
OBJDUMP = objdump

INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
TESTBIN_DIR = ./testbin

PKGS = 

#DEBUG_MODE=TRUE
ifdef DEBUG_MODE
DEFINES  += -DDEBUG
CFLAGS   += -g -ggdb -D_GLIBCXX_DEBUG
else 
CFLAGS   += -O3
endif

INCLUDE         += -I $(INC_DIR)
CFLAGS          +=  -Wall
LDFLAGS         += 
TESTLDFLAGS     += -lgtest -lgtest_main  -lpthread
CPPFLAGS        += -std=c++14 
PROJ_NAME       = proj3
TESTSIXMENS_NAME  = testsixmensmorris
MAIN_OBJ        = $(OBJ_DIR)/main.o

TESTSIXMENS_OBJ    = $(OBJ_DIR)/testsixmensmorris.o

PROJ_OBJS       = $(OBJ_DIR)/SixMensMorrisBoard.o     

            
            
all: directories test $(BIN_DIR)/$(PROJ_NAME)
test: $(TESTBIN_DIR)/$(TESTSIXMENS_NAME)
	$(TESTBIN_DIR)/$(TESTSIXMENS_NAME)
	
$(BIN_DIR)/$(PROJ_NAME): $(PROJ_OBJS) $(MAIN_OBJ)
	$(CXX) $(MAIN_OBJ) $(PROJ_OBJS) -o $(BIN_DIR)/$(PROJ_NAME) $(CFLAGS) $(CPPFLAGS) $(DEFINES) $(LDFLAGS) 
	
$(TESTBIN_DIR)/$(TESTSIXMENS_NAME): $(PROJ_OBJS) $(TESTSIXMENS_OBJ)
	$(CXX) $(PROJ_OBJS) $(TESTSIXMENS_OBJ) -o $(TESTBIN_DIR)/$(TESTSIXMENS_NAME) $(CFLAGS) $(CPPFLAGS) $(DEFINES) $(TESTLDFLAGS) 

	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(DEFINES) $(INCLUDE) -c $< -o $@
	
.PHONY: directories
directories:
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(TESTBIN_DIR)
	
clean::
	-rm $(OBJ_DIR)/*.o $(INC_DIR)/*.*~ $(SRC_DIR)/*.*~
	
.PHONY: clean