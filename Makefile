CXX = clang++ 
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -Werror
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj
LIB_DIR = lib

# Find all cpp files in src directory
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Generate object file names
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
# Generate executable names
EXECS = $(SRCS:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%)

# Default target
all: $(LIB_DIR) $(BIN_DIR) $(OBJ_DIR) $(EXECS)

# Combined directory creation
$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

$(LIB_DIR):
	mkdir -p $@

# Rule to compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link object files into executables
$(BIN_DIR)/%: $(OBJ_DIR)/%.o
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean target
.PHONY: clean
clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)

