# CPP files
CPPFILES := converter.cpp dollartoeuroconverter.cpp TemperatureConverter.cpp

# minimal makefile for SE class
all: main

# main depends on all cpp files
main: $(patsubst %.cpp,%.o,$(CPPFILES) main.cpp)
	g++ -Wall -o $@ $^

test: $(patsubst %.cpp,%.o,$(CPPFILES) tinytest.cpp)
	g++ -Wall -o $@ $^

# a slightly ugly hack to make .o depend on .hpp if it exists
.SECONDEXPANSION:
%.o: %.cpp $$(wildcard $$*.hpp)
	g++ -Wall -std=c++11 -c -o $@ $<

clean:
	rm main *.o
