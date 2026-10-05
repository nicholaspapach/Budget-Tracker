# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g -std=c++20

# Target executable
TARGET = PBT

# For deleting the target
TARGET_DEL = PBT

# Source files
SRCS = src/main.cpp src/transaction.cpp src/fileHandler.cpp

# Objects files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the executable
all: $(TARGET) run

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
# Rule to run the executable
run: $(TARGET)
	./$(TARGET)

# Clean rule to remove generated files
clean:
	rm -f $(TARGET_DEL) $(OBJS)	