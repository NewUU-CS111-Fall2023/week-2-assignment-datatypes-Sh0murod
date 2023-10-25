all: a.out

a.out:
	g++ -std=c++11 src/cpp/main.cpp

test: a.out
	./a.out

clean:
	rm a.out