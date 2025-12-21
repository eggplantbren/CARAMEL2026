CC = g++
CXXFLAGS = -O2 -std=c++17 -Wall -Wextra -pedantic
DNEST4_PATH = /home/brewer/Projects

default:

    # Compile source files
	$(CXX) $(CXXFLAGS) -I $(DNEST4_PATH)/DNest4/code -c Array2D.cpp
	$(CXX) $(CXXFLAGS) -I $(DNEST4_PATH)/DNest4/code -c Continuum.cpp

    # Compile tests
	$(CXX) $(CXXFLAGS) -I $(DNEST4_PATH)/DNest4/code -o test_Array2D tests/Array2D.cpp Array2D.o
	$(CXX) $(CXXFLAGS) -I $(DNEST4_PATH)/DNest4/code -L $(DNEST4_PATH)/DNest4/code -o test_Continuum tests/Continuum.cpp Continuum.o -ldnest4
