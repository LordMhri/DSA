# Makefile to compile check.cpp

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Target executable
TARGET = check

# Source files
SRCS = check.cpp

# Default target
all: $(TARGET)

# Rule to compile source files and create the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean up build files
clean:
	rm -f $(TARGET)

.PHONY: all clean
