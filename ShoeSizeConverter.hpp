
//  SoftwareEng
//

//  Copyright (c) 2014 Jula McGibbon and Benjamin Linz. All rights reserved.
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
    static converter *create();
};


class DEToITConverter: public ShoeSizeConverter
{
public:
    double convert(double inShoeSize);
    std::string toString() const;
    static converter *create();
};


class UKToITConverter: public ShoeSizeConverter
{
public:
    double convert(double inShoeSize);
    std::string toString() const;
    static converter *create();
};

class ITToDEConverter: public ShoeSizeConverter
{
public:
    double convert(double inShoeSize);
    std::string toString() const;
    static converter *create();
};



#endif // SHOESIZECONVERTER_H
