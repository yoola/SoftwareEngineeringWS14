#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <string>

class converter
{
  public:
    virtual double convert(double inValue) = 0;
    virtual std::string toString() const = 0;
    virtual void print() const;
};

#endif // CONVERTER_H
