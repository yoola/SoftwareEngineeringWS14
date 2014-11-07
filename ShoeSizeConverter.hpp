//
//  DEToUKConverter.h
//  
//
//  Created by Jula McGibbon on 07.11.14.
//
//  SoftwareEng
//
//  Created by Jula McGibbon on 05.11.14.
//  Copyright (c) 2014 Jula McGibbon. All rights reserved.
//

#ifndef SHOESIZECONVERTER_H
#define SHOESIZECONVERTER_H

#include "converter.hpp"


class ShoeSizeConverter: public converter
{
};

class DEToUKConverter: public ShoeSizeConverter
{
public:
    double convert(double inShoeSize);
    std::string toString() const;
};


class DEToITConverter: public ShoeSizeConverter
{
public:
    double convert(double inShoeSize);
    std::string toString() const;
};


#endif // SHOESIZECONVERTER_H
