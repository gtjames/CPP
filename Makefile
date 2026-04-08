CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Find all .cpp files
PROJECTS := $(wildcard */)
SRCS = $(wildcard */src/*.cpp)
# SRC := $(shell find . -type f -path "*/src/*.cpp")
# OBJ := $(SRC:.cpp=.o)

# Convert file.cpp → file
TARGETS = $(SRCS:.cpp=)

all:
	for dir in $(PROJECTS); do \
		echo "Building project in $$dir"; \
		$(MAKE) -C $$dir; \
	done

mySQL: mySQL.cpp
	$(CXX) $(CXXFLAGS) mySQL.cpp -o mySQL -I/opt/homebrew/include -L/opt/homebrew/lib -lmysqlcppconnx
# Rule: build each executable from its .cpp
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean up executables
clean:
	rm -f $(TARGETS)

