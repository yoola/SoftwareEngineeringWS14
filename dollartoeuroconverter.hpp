#ifndef DOLLARTOEUROCONVERTER_H
#define DOLLARTOEUROCONVERTER_H

#include "converter.hpp"

class dollarToEuroConverter : public converter
{
  public:
    dollarToEuroConverter();
    double convert(double inDollars);
    std::string toString() const;
    void print() const;
};

#endif // DOLLARTOEUROCONVERTER_H
