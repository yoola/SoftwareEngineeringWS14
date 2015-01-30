//
//  ConverterExceptions.cpp
//  SoftEngineering2
//
//  Created by Jula McGibbon and Benjamin Linz on 28.01.15.
//  Copyright (c) 2015 Jula McGibbon and Benjamin Linz. All rights reserved.
//

#include "ConverterExceptions.hpp"
#include <string>
#include <sstream>
#include <iostream>

CurrencyConverterException::CurrencyConverterException(double invalue) {
    this -> message = message + convertDoubleToString(invalue) +"\n";
}

std::string CurrencyConverterException::convertDoubleToString(double invalue){
    ostringstream str;
    str << invalue;
    return str.str();
}