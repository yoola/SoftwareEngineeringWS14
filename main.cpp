#include <string>
#include <iostream>
#include <sstream>
#include "converter.hpp"

int main(int argc, char* argv[])
{
    std::string conversion, value_string;

    if (argc == 3) {
        conversion = argv[1];
        value_string = argv[2];
    }
    else {
        std::cout << "Sie haben folgende Eingabemöglichkeiten: \n\
        - Eine Conversion (Bsp: DEToUK 40) \n\
        - Mehrere Conversionen hintereinander (Bsp: DEToUK UKToIT ITToDE 40) \n\
        - Inversionen hinzufügen (Bsp: DEToIT UKToIT^-1 40)\n";
        std::ostringstream conv_stream;
        std::string cur;
        std::cin >> cur;
        do {
            conv_stream << " " << cur;
            std::cin >> cur;
        } while (!std::isdigit(cur[0]));    // test if string could be a number
        conversion = conv_stream.str();
        value_string = cur;
    }

    // Convert string to double
    std::istringstream value_stream(value_string);
    double value;
    value_stream >> value;

    /*
     * use desired conversion here
     *
     */
    Factory *factory = Factory::getFactory();
    converter* myConverter = factory->create(conversion);

    double converted_value = myConverter->convert(value);

    std::cout << myConverter->toString() << " has converted " << value << " to " << converted_value << "!" << std::endl;
    delete myConverter;
    return 0;
}
