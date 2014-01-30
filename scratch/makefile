objects = func.o main.o

all: prog

prog: $(objects)
	$(CXX) -o prog $(objects)

main.o: main.cpp
	$(CXX) -c -o main.o main.cpp

func.o: func.cpp a.h
	$(CXX) -c -o func.o func.cpp

clean:
	rm prog $(objects)