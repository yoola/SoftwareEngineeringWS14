#ifndef DOLLARTOEUROCONVERTER_H
#define DOLLARTOEUROCONVERTER_H

#include "converter.hpp"

class dollarToEuroConverter : public converter
{
  public:
    double convert(double inDollars);
    std::string toString() const;
};

#endif // DOLLARTOEUROCONVERTER_H
