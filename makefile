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
%.o: src/%.cpp
	$(CC) $(VERSION) -c src/$*.cpp -o $(OBJ_DIR)/$*.o

# Primary source compilation
src_comp:
	make -s Main.o
	make -s Producer.o
	make -s Consumer.o
	make -s BufManip.o

# Program binary executable compilation
program: src_comp
	g++ $(OBJ_DIR)/*.o -o $(BIN_DIR)/$(BIN) $(RTL) $(LPTHREAD)

# Clean does a recursive removal of the generated bin and obj directories.
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
