//
//  CompositeConverter.cpp
//  
//
//  Created by Jula McGibbon  and Benjamin Linz on 14.12.14.
//
//

#include <stdio.h>
#include "CompositeConverter.hpp"

CompositeConverter::CompositeConverter(converter *converter1, converter *converter2)
    : converter1(converter1), converter2(converter2) {}

CompositeConverter::~CompositeConverter()
{
    delete converter1;
    delete converter2;
}

double CompositeConverter::convert(double inValue)
{
    double intermediate = converter1->convert(inValue);
    return converter2->convert(intermediate);
}

std::string CompositeConverter::toString() const
{
    return converter1->toString() + " concatenated with " + converter2->toString();
}

converter *CompositeConverter::create(converter *converter1, converter *converter2)
{
    return new CompositeConverter(converter1, converter2);
}