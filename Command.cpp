//
//  Command.cpp
//  
//
//  Created by Jula McGibbon and Benjamin Linz on 14.12.14.
//
//




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


#include "Command.hpp"
#include "converter.hpp"
#include "ConversionExceptions.hpp"
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
    try{
        output = myConverter->convert(input);
    } catch(CurrencyConversionException* cce){
        std::cout<< cce->what() <<"\n";
    }
    
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