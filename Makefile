# minimal makefile for SE class
all: main test

# main depends on all cpp files
main: $(patsubst %.cpp,%.o,$(wildcard *.cpp))
	g++ -Wall -o $@ $^

# a slightly ugly hack to make .o depend on .hpp if it exists
.SECONDEXPANSION:
%.o: %.cpp $$(wildcard $$*.hpp)
	g++ -Wall -c -o $@ $<

test:
	./main

clean:
	rm main *.o

