#include "converter.hpp"
#include "TemperatureConverter.hpp"
#include "dollartoeuroconverter.hpp"
#include "ShoeSizeConverter.hpp"
#include "CompositeConverter.hpp"
#include "InverseConverter.hpp"
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
    if (name.substr(name.size() - 3, 3) == "^-1") {
        converter *conv = create_single(name.substr(0, name.size() - 3));
        return InverseConverter::create(conv);
    }
    else
        return (table[name])();
}
