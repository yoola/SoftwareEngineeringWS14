//
//  ShoeSizeConverter.cpp
//
//  Copyright (c) 2014 Jula McGibbon and Benjamin Linz. All rights reserved.


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



#include "ShoeSizeConverter.hpp"
#include "ConversionExceptions.hpp"
#include <cmath>

//tinytest testcases don't work anymore because of added rounding function

double DEToUKConverter::convert(double deSize){
	if ((deSize<32.0 ^ deSize>49.5) || fmod(deSize * 2, 2.0) != 0)	//out of range or not a 0.5 step
		throw new ShoeSizeConversionException(deSize, "DE");
	double ukSize = ((deSize * 2) / 2.54) - 25.0;
	return (round(ukSize*2)/2); //round in 0.5 steps //does it work with inverse?
}

std::string DEToUKConverter::toString() const{
    return "DE to UK Converter";
}

converter *DEToUKConverter::create()
{
    return new DEToUKConverter;
}


/* old
double DEToITConverter::convert(double inputShoeSize){
    return (((inputShoeSize/0.667)-1.5)*0.667);
}

std::string DEToITConverter::toString() const{
    return "DE to IT Converter";
}

converter *DEToITConverter::create()
{
    return new DEToITConverter;
}
*/




double UKToITConverter::convert(double ukSize){
	if ((ukSize<0.0 ^ ukSize>14.0) || fmod(ukSize * 2, 2.0) != 0)	//out of range or not a 0.5 step
		throw new ShoeSizeConversionException(ukSize, "UK");
    /*we took the formulas (DEToUK, DEToIT) from http://www.blitzrechner.de/schuhgroessen-berechnen/,
	 (since the DEToUK one contains a parenthesis error, we fixed the error by adding the missing parenthesis)
     set each up for DE, equal those two equations, assuming that 0,667 actually means 2/3 (Paris point)
     and get the following formula (although there is no direct conversion between UK <-> IT and the computed
     annotation: to fix: computed itSize is round 1 unit smaller using the example calculator on the above website (equation from website doesn't work properly -> slightly wrong) */
	double itSize = ((((ukSize + 25) * 2.54) / (2 * (2.0/3))) - 1.5) * (2.0/3);
	return (round(itSize * 2.0)/2.0); //round in 0.5 steps //does it work with inverse?
}

std::string UKToITConverter::toString() const{
    return "UK to IT Converter";
}

converter *UKToITConverter::create()
{
    return new UKToITConverter();
}





double ITToDEConverter::convert(double itSize){
	if ((itSize<31.0 ^ itSize>48.5) || fmod(itSize * 2, 2.0) != 0)	//out of range or not a 0.5 step
		throw new ShoeSizeConversionException(itSize, "IT");
    //similar to UKToITConverter; set up equation and the resulting size differs however also from the result which is computed by the example calculator..
	double deSize = ((itSize / (2.0 / 3)) + 1.5) * (2.0 / 3);
    return (round(deSize*2)/2); //round in 0.5 steps //does it work with inverse?
}

std::string ITToDEConverter::toString() const{
    return "IT to DE Converter";
}

converter *ITToDEConverter::create()
{
    return new ITToDEConverter();
}
