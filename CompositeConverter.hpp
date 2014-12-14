//
//  CompositeConverter.hpp
//  
//
//  Created by Jula McGibbon and Benjamin Linz on 14.12.14.
//
//

#ifndef _CompositeConverter_hpp
#define _CompositeConverter_hpp
#include "converter.hpp"

class CompositeConverter : public converter {
public:
    CompositeConverter(converter *converter1, converter *converter2);
    ~CompositeConverter();
    double convert(double inValue);
    std::string toString() const;
    static converter *create(converter *converter1, converter *converter2);

private:
    converter *converter1, *converter2;
};

#endif
