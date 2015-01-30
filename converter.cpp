

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


#include "converter.hpp"
#include "TemperatureConverter.hpp"
#include "dollartoeuroconverter.hpp"
#include "ShoeSizeConverter.hpp"
#include "CompositeConverter.hpp"
#include "InverseConverter.hpp"
#include "ConversionExceptions.hpp"
#include <sstream>
#include <stdexcept>

void converter::print() const
{
    std::cout<<this->toString();
}

/**
 * Converter Factory
 */

Factory Factory::factory;

Factory::Factory()
{
    table["CelsiusToFahrenheit"] = CelsiusToFahrenheitConverter::create;
    /*old 
	table["FahrenheitToCelsius"] = FahrenheitToCelsiusConverter::create;*/
	table["FahrenheitToKelvin"] = FahrenheitToKelvinConverter::create;
    table["KelvinToCelsius"] = KelvinToCelsiusConverter::create;
	/* old
	table["CelsiusToKelvin"] = CelsiusToKelvinConverter::create;*/
    table["DollarToEuro"] = dollarToEuroConverter::create;
    table["DEToUK"] = DEToUKConverter::create;
	/*old
	table["DEToIT"] = DEToITConverter::create;*/
    table["UKToIT"] = UKToITConverter::create;
    table["ITToDE"] = ITToDEConverter::create;
}

Factory* Factory::getFactory()
{
    return &factory;
}

converter* Factory::create(const std::string &names)
{
    std::istringstream stream(names);
    std::string cur;
    converter *conv = nullptr;

    while (stream >> cur) {
        if (conv) {
            converter *conv2 = create_single(cur);
            conv = CompositeConverter::create(conv, conv2);
        }
        else {
            conv = create_single(cur);
        }
    }

    return conv;
}

converter* Factory::create_single(const std::string &name)
{
    if (name.substr(name.size() - 3, 3) == "?-1") {
        converter *conv = create_single(name.substr(0, name.size() - 3));
        return InverseConverter::create(conv);
    }
    else {
        std::map<std::string, pcreate>::iterator it = table.find(name);
        if (it != table.end())
            return (it->second)();
        else
            throw new ConverterNotFoundException(name);
    }
}
