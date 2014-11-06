#include <string>
#include <iostream>
#include <sstream>
#include "converter.hpp"

int main(int argc, char* argv[])
{
    std::string conversion = argv[1];
    std::string value_string = argv[2];

    // Convert string to double
    std::istringstream value_stream(value_string);
    double value;
    value_stream >> value;

    /*
     * use desired conversion here
     *
     */
    Factory factory;
    converter* myConverter = factory.create(conversion);

    double converted_value = myConverter->convert(value);

    std::cout << myConverter->toString() << " has converted " << value << " to " << converted_value << "!" << std::endl;
    return 0;
}
