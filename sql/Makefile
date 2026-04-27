CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Find all .cpp files
SRCS = $(wildcard *.cpp)

# Convert file.cpp → file
TARGETS = $(SRCS:.cpp=)

all: $(TARGETS)

select: select.cpp
	$(CXX) $(CXXFLAGS) select.cpp -o select -I/opt/homebrew/include -L/opt/homebrew/lib -lmysqlcppconnx

mySQL: mySQL.cpp
	$(CXX) $(CXXFLAGS) mySQL.cpp -o mySQL -I/opt/homebrew/include -L/opt/homebrew/lib -lmysqlcppconnx

sql: sql.cpp
	$(CXX) $(CXXFLAGS) sql.cpp -o sql -I/opt/homebrew/include -L/opt/homebrew/lib -lmysqlcppconnx

# Rule: build each executable from its .cpp
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean up executables
clean:
	rm -f $(TARGETS)

