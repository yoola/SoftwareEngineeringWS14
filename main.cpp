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
        std::cout << "Geben sie ein was sie konvertieren wollen und die Zahl: ";
        std::cin >> conversion;
        std::cin >> value_string;
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
