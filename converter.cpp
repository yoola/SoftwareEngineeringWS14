#include "converter.hpp"
#include "TemperatureConverter.hpp"
#include "dollartoeuroconverter.hpp"
#include "ShoeSizeConverter.hpp"
#include "CompositeConverter.hpp"
#include <sstream>

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
    table["FahrenheitToCelsius"] = FahrenheitToCelsiusConverter::create;
    table["KelvinToCelsius"] = KelvinToCelsiusConverter::create;
    table["CelsiusToKelvin"] = CelsiusToKelvinConverter::create;
    table["DollarToEuro"] = dollarToEuroConverter::create;
    table["DEToUK"] = DEToUKConverter::create;
    table["DEToIT"] = DEToITConverter::create;
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
            converter *conv2 = (table[cur])();
            conv = CompositeConverter::create(conv, conv2);
        }
        else {
            conv = (table[cur])();
        }
    }

    return conv;
}
