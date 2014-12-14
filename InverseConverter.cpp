//
//  InverseConverter.cpp
//  
//
//  Created by Jula McGibbon on 14.12.14.
//
//

#include "InverseConverter.hpp"

InverseConverter::InverseConverter(converter *conv)
: conv(conv) {}

InverseConverter::~InverseConverter()
{
    delete conv;
}

double InverseConverter::convert(double inValue)
{
    // Assume converter is of the form convert(x) = m*x + n
    double n = conv->convert(0.0), m = conv->convert(1.0) - n;
    return (inValue - n) / m;
}

std::string InverseConverter::toString() const
{
    return std::string("Inverted (") + conv->toString() + std::string(")");
}

converter *InverseConverter::create(converter *conv)
{
    return new InverseConverter(conv);
}