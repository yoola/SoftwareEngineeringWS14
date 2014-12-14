//
//  ShoeSizeConverter.cpp
//
//  Copyright (c) 2014 Jula McGibbon and Benjamin Linz. All rights reserved.




#include "ShoeSizeConverter.hpp"
#include <string>


double DEToUKConverter::convert(double inputShoeSize){
    return (((inputShoeSize*2)/2.54)-25.0);
}

std::string DEToUKConverter::toString() const{
    return "DE to UK Converter";
}

converter *DEToUKConverter::create()
{
    return new DEToUKConverter;
}



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





double UKToITConverter::convert(double ukSize){
    /*we took the formulas (DEToUK, DEToIT) from http://www.blitzrechner.de/schuhgroessen-berechnen/,
     set each up for DE, equal those two equations, assume that 0.667 should be (2/3)
     and get the following formula (although there is no direct conversion between UK <-> IT and the computed
     itSize is round 1 unit smaller using the example calculator of website http://www.blitzrechner.de/uk-schuhgroesse-umrechnen/) */
    return (((((ukSize + 25) * 2.54) / (2 * 0.667)) - 1.5) * 0.667);
}

std::string UKToITConverter::toString() const{
    return "UK to IT Converter";
}

converter *UKToITConverter::create()
{
    return new UKToITConverter();
}





double ITToDEConverter::convert(double itSize){
    //similar to UKToITConverter; set up equation and the resulting size differs however from the result which is computed by the example calculator..
    return (((itSize / (2.0/3)) + 1.5) * (2.0/3));
}

std::string ITToDEConverter::toString() const{
    return "IT to DE Converter";
}

converter *ITToDEConverter::create()
{
    return new ITToDEConverter();
}
