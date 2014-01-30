all: prog

prog: func.o
	$(CXX) -o prog func.o main.cpp

func.o: func.cpp a.h
	$(CXX) -c -o func.o func.cpp 