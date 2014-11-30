#include "converter.hpp"
#include "TemperatureConverter.hpp"
#include "dollartoeuroconverter.hpp"
#include "ShoeSizeConverter.hpp"

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
    table["DollarToEuro"] = dollarToEuroConverter::create;
    table["DEToUK"] = DEToUKConverter::create;
    table["DEToIT"] = DEToITConverter::create;
}

Factory* Factory::getFactory()
{
    return &factory;
}

converter* Factory::create(const std::string &name)
{
    return (table[name])();
}
