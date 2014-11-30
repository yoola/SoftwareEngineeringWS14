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
