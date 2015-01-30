
//  SoftwareEng

//  Copyright (c) 2014 Jula McGibbon and Bejamin Linz. All rights reserved.
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

class FahrenheitToKelvinConverter : public TemperatureConverter
{
public:
	double convert(double inFahrenheit);
	std::string toString() const;
	static converter *create();
};

/*old
class FahrenheitToCelsiusConverter: public TemperatureConverter
{
public:
    double convert(double inFahrenheit);
    std::string toString() const;
    static converter *create();
};
*/

class KelvinToCelsiusConverter: public TemperatureConverter
{
public:
    double convert(double inKelvin);
    std::string toString() const;
    static converter *create();

};

/*old
class CelsiusToKelvinConverter: public TemperatureConverter
{
public:
    double convert(double inCelsius);
    std::string toString() const;
    static converter *create();
};
*/



#endif // TEMPERATURECONVERTER_H
