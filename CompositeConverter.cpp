//
//  CompositeConverter.cpp
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