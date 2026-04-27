CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Find all .cpp files
SRCS = $(wildcard *.cpp)

# Convert file.cpp → file
TARGETS = $(SRCS:.cpp=)

all: $(TARGETS)

# Rule: build each executable from its .cpp
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean up executables
clean:
	rm -f $(TARGETS)

