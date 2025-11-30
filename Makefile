CC = g++
CXXFLAGS = -O2 -std=c++17 -Wall -Wextra -pedantic

default:

    # Compile source files
	$(CXX) $(CXXFLAGS) -c Array2D.cpp

    # Compile tests
	$(CXX) $(CXXFLAGS) -o test_Array2D tests/Array2D.cpp Array2D.o

