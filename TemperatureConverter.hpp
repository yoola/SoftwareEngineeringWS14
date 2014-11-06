//
//  CelsiusToFahrenheitConverter.h
//  SoftwareEng
//
//  Created by Jula McGibbon on 05.11.14.
//  Copyright (c) 2014 Jula McGibbon. All rights reserved.
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
};

class FahrenheitToCelsiusConverter: public TemperatureConverter
{
public:
    double convert(double inFahrenheit);
    std::string toString() const;
};

class KelvinToCelsiusConverter: public TemperatureConverter
{
public:
    double convert(double inKelvin);
    std::string toString() const;
};


#endif // TEMPERATURECONVERTER_H
