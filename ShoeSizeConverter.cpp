//
//  ShoeSizeConverter.cpp
//  
//
//  Created by Jula McGibbon on 07.11.14.
//
//


#include "ShoeSizeConverter.hpp"
#include <string>


double DEToUKConverter::convert(double inputShoeSize){
    return (((inputShoeSize*2)/2.54)-25.0);
}

std::string DEToUKConverter::toString() const{
    return "DE to UK Converter";
}


double DEToITConverter::convert(double inputShoeSize){
    return (((inputShoeSize/0.667)-1.5)*0.667);
}

std::string DEToITConverter::toString() const{
    return "DE to IT Converter";
}



