//
//  InverseConverter.h
//  
//
//  Created by Jula McGibbon  and Benjamin Linz on 14.12.14.
//
//

#ifndef ____InverseConverter__
#define ____InverseConverter__
#include "converter.hpp"

class InverseConverter : public converter {
public:
    InverseConverter(converter *conv);
    ~InverseConverter();
    double convert(double inValue);
    std::string toString() const;
    static converter *create(converter *conv);

private:
    converter *conv;
};

#endif
