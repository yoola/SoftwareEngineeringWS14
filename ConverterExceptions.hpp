//
//  ConverterExceptions.hpp
//  SoftEngineering2
//
//  Created by Jula McGibbon and Benjamin Linz on 28.01.15.
//  Copyright (c) 2015 Jula McGibbon and Benjamin Linz. All rights reserved.
//

#ifndef CONVERTEREXCEPTIONS_H
#define CONVERTEREXCEPTIONS_H

#include <stdio.h>
#include <exception>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;



class CurrencyConverterException : public exception
{
public:
    CurrencyConverterException(double invalue);
    virtual ~CurrencyConverterException() throw() {}
    virtual const char * what() const throw()
    {return message.c_str();}
    
private:
    string message = "A negative input value is not allowed for currencies.\n\t Your input value was: ";
    string convertDoubleToString(double invalue);
    
    /*Exception(const char* message){
        m = message;
    }*/
    /*CurrencyConverterException(){
        std::exception("");
    }*/
};

#endif // CONVERTEREXCEPTIONS_H