//
//  CelsiusToFahrenheitConverter.cpp
//  SoftwareEng
//
//  Created by Jula McGibbon on 05.11.14.
//  Copyright (c) 2014 Jula McGibbon. All rights reserved.
//

#include "TemperatureConverter.hpp"
#include <string>

/*In: double value of celsius
 *Out: fahrenheit value of input celsius
 */
double CelsiusToFahrenheitConverter::convert(double inputCelsius){
    return ((inputCelsius*1.8)+32);
}

std::string CelsiusToFahrenheitConverter::toString() const{
    return "Celsius To Fahrenheit Converter";
}

converter *CelsiusToFahrenheitConverter::create()
{
    return new CelsiusToFahrenheitConverter;
}

double FahrenheitToCelsiusConverter::convert(double inputFahrenheit){
    return ((inputFahrenheit-32)/1.8);
}

std::string FahrenheitToCelsiusConverter::toString() const{
    return "Fahrenheit to Celsius Converter";
}

converter *FahrenheitToCelsiusConverter::create()
{
    return new FahrenheitToCelsiusConverter;
}

double KelvinToCelsiusConverter::convert(double inputKelvin){
    return (inputKelvin-273.15);
}

std::string KelvinToCelsiusConverter::toString() const{
    return "Kelvin to Celsius Converter";
}

converter *KelvinToCelsiusConverter::create()
{
    return new KelvinToCelsiusConverter;
}
