//
//  InverseConverter.cpp
//  
//
//  Created by Jula McGibbon  and Benjamin Linz on 14.12.14.
//
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