
//  SoftwareEng

//  Copyright (c) 2014 Jula McGibbon and Benjamin Linz. All rights reserved.
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


#include "TemperatureConverter.hpp"
#include "ConversionExceptions.hpp"

/*In: double value of celsius
 *Out: fahrenheit value of input celsius
 */
double CelsiusToFahrenheitConverter::convert(double inputCelsius){
	if (inputCelsius < -273.15)	//below absolute zero
		throw new TemperatureConversionException(inputCelsius, 'C');
    return ((inputCelsius*1.8)+32);
}

std::string CelsiusToFahrenheitConverter::toString() const{
    return "Celsius to Fahrenheit Converter";
}

converter *CelsiusToFahrenheitConverter::create()
{
    return new CelsiusToFahrenheitConverter;
}

/*old
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
*/

double FahrenheitToKelvinConverter::convert(double inputFahrenheit){
	if (inputFahrenheit < -459.67)	//below absolute zero
		throw new TemperatureConversionException(inputFahrenheit, 'F');
	return (((inputFahrenheit - 32) / 1.8) + 273.15);
}

std::string FahrenheitToKelvinConverter::toString() const{
	return "Fahrenheit to Kelvin Converter";
}

converter *FahrenheitToKelvinConverter::create()
{
	return new FahrenheitToKelvinConverter;
}

double KelvinToCelsiusConverter::convert(double inputKelvin){
	if (inputKelvin < 0.0)	//below absolute zero
		throw new TemperatureConversionException(inputKelvin, 'K');
    return (inputKelvin-273.15);
}

std::string KelvinToCelsiusConverter::toString() const{
    return "Kelvin to Celsius Converter";
}

converter *KelvinToCelsiusConverter::create()
{
    return new KelvinToCelsiusConverter;
}

/*old
double CelsiusToKelvinConverter::convert(double inputCelsius){
    return (inputCelsius+273.15);
}

std::string CelsiusToKelvinConverter::toString() const{
    return "Celsius to Kelvin Converter";
}

converter *CelsiusToKelvinConverter::create()
{
    return new CelsiusToKelvinConverter;
}
*/