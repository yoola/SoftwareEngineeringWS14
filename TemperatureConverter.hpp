
//  SoftwareEng

//  Copyright (c) 2014 Jula McGibbon and Bejamin Linz. All rights reserved.
//

#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H

#include "converter.hpp"


class TemperatureConverter: public converter
{
};

class CelsiusToFahrenheitConverter: public TemperatureConverter
{
public:
    double convert(double inCelsius);
    std::string toString() const;
    static converter *create();
};

class FahrenheitToCelsiusConverter: public TemperatureConverter
{
public:
    double convert(double inFahrenheit);
    std::string toString() const;
    static converter *create();
};

class KelvinToCelsiusConverter: public TemperatureConverter
{
public:
    double convert(double inKelvin);
    std::string toString() const;
    static converter *create();

};

class CelsiusToKelvinConverter: public TemperatureConverter
{
public:
    double convert(double inCelsius);
    std::string toString() const;
    static converter *create();
};




#endif // TEMPERATURECONVERTER_H
