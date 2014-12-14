//
//  Command.cpp
//  
//
//  Created by Jula McGibbon and Benjamin Linz on 14.12.14.
//
//

#include "Command.hpp"
#include "converter.hpp"
#include <sstream>

Command::Command(std::string conversion, std::string value_string)
    : conversion(conversion), value_string(value_string) {}

bool Command::execute()
{
    // Convert string to double
    std::istringstream value_stream(value_string);
    value_stream >> input;

    Factory *factory = Factory::getFactory();
    converter* myConverter;
    try {
        myConverter = factory->create(conversion);
    }
    catch (std::runtime_error &error) {
        std::cout << "Error: " << error.what() << std::endl;
        return false;
    }

    description = myConverter->toString();
    output = myConverter->convert(input);
    delete myConverter;
    return true;
}

std::string Command::getDescription() const
{
    return description;
}

double Command::getInput() const
{
    return input;
}

double Command::getOutput() const
{
    return output;
}