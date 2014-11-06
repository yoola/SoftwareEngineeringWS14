#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <string>
#include <map>

class converter
{
  public:
    virtual double convert(double inValue) = 0;
    virtual std::string toString() const = 0;
    virtual void print() const;
};

class Factory {
public:
    Factory();
    converter* create(std::string name);

private:
    enum class type;
    std::map<std::string, type> table;
};

#endif // CONVERTER_H
