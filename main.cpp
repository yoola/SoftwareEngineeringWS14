#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "converter.hpp"
#include "Command.hpp"

int main(int argc, char* argv[])
{
    std::cout << "Sie haben folgende Eingabemöglichkeiten: \n\
    - Eine Conversion (Bsp: DEToUK 40) \n\
    - Mehrere Conversionen hintereinander (Bsp: DEToUK UKToIT ITToDE 40) \n\
    - Inversionen hinzufügen (Bsp: DEToIT UKToIT^-1 40)\n\n\
    Sie können mehrere Befehle eingeben und durch Strg+D die Eingabe beenden\n";

    CommandQueue queue;
    std::string cur;
    while (std::cin >> cur) {
        std::string conversion, value_string;
        std::ostringstream conv_stream;
        do {
            conv_stream << " " << cur;
            std::cin >> cur;
        } while (!std::isdigit(cur[0]));    // test if string could be a number
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
