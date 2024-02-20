# Executable name
BIN=BoundBuf

# Directories
OBJ_DIR=obj
BIN_DIR=bin

# Linker, version, and misc additions
CC=cc
VERSION=-std=c++11
RTL=-lrt
LPTHREAD=-lpthread

# All call
all: directories program

# Make all of these directories if they don't exist
directories:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

# General compilation rule
$(OBJ_DIR)/%.o: src/%.cpp
	$(CC) $(VERSION) -c $* -o $*.o

# Primary source compilation
src_comp: src/*.cpp
	make $(OBJ_DIR)/Main.o
	make $(OBJ_DIR)/Producer.o
	make $(OBJ_DIR)/Consumer.o
	make $(OBJ_DIR)/BufManip.o

# Program binary executable compilation
program: src_comp
	g++ $(OBJ_DIR)/*.o -o $(BIN_DIR)/$(BIN) $(RTL) $(LPTHREAD)

# Clean does a recursive removal of the generated bin and obj directories.
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
