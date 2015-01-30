

/*
 
 The MIT License (MIT)
 
 Copyright (c) 2015, Benjamin Linz and Jula McGibbon
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 
 
 */




#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "converter.hpp"
#include "Command.hpp"

int main(int argc, char* argv[])
{
    std::cout << "You have following input possibilites: \n\
	- A conversion (e.g.: DEToUK 40) \n\
	- Concatenate/'stacking' conversions (e.g.: DEToUK UKToIT ITToDE 40) \n\
	- Use inverted conversion (e.g.: DEToIT UKToIT?-1 40)\n\n\
	- Existing conversions: DollarToEuro, CelsiusToFahrenheit, FahrenheitToKelvin, KelvinToCelsius, DEToUK, UKToIT, ITToDE\n\n\
	You can enter several commands and execute them in the order they were entered by pressing Ctrl+D\n";

    CommandQueue queue;
    std::string cur;
    while (std::cin >> cur) {
        std::string conversion, value_string;
        std::ostringstream conv_stream;
        do {
            conv_stream << " " << cur;
            std::cin >> cur;
        } while (!isdigit(cur[0]) && cur[0]!='-');    // test if string could be a number or '-'
        conversion = conv_stream.str();
        value_string = cur;
        queue.push(Command(conversion, value_string));
    }

    while (queue.size()) {
        Command comm = queue.front();
        if (comm.execute())
            std::cout << comm.getDescription() << " has converted " << comm.getInput() <<
                " to " << comm.getOutput() << "!" << std::endl;
        queue.pop();
    }

    return 0;
}
