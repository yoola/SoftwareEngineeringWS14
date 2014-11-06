#include "converter.hpp"
#include "TemperatureConverter.hpp"
#include "dollartoeuroconverter.hpp"

void converter::print() const
{
    std::cout<<this->toString();
}

/**
 * Converter Factory
 */

enum class Factory::type {
    DEFAULT = 0,
    CELSIUS_TO_FAHRENHEIT,
    FAHRENHEIT_TO_CELSIUS,
    KELVIN_TO_CELSIUS,
    DOLLAR_TO_EURO
};

Factory::Factory()
{
    table["CelsiusToFahrenheit"] = type::CELSIUS_TO_FAHRENHEIT;
    table["FahrenheitToCelsius"] = type::FAHRENHEIT_TO_CELSIUS;
    table["KelvinToCelsius"] = type::KELVIN_TO_CELSIUS;
    table["DollarToEuro"] = type::DOLLAR_TO_EURO;
}

converter* Factory::create(std::string name)
{
    switch (table[name]) {
        case type::DEFAULT:
            return nullptr;

        case type::CELSIUS_TO_FAHRENHEIT:
            return new CelsiusToFahrenheitConverter();

        case type::FAHRENHEIT_TO_CELSIUS:
            return new FahrenheitToCelsiusConverter();

        case type::KELVIN_TO_CELSIUS:
            return new KelvinToCelsiusConverter();

        case type::DOLLAR_TO_EURO:
            return new dollarToEuroConverter();
    }
}
