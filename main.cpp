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
