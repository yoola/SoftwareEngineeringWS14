#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <string>
#include <map>

class converter
{
  public:
    virtual ~converter() {}
    virtual double convert(double inValue) = 0;
    virtual std::string toString() const = 0;
    virtual void print() const;
};

class Factory {
public:
    converter* create(const std::string &name);
    static Factory* getFactory();

    //alternativ:
    // void registerClass(std::string name, pcreate);
    // void unregisterClass(std::string name);

protected:
    Factory();

private:
    typedef converter* (*pcreate)();
    static Factory factory;
    std::map<std::string, pcreate> table;
};

#endif // CONVERTER_H
