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
