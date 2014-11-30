#include "dollartoeuroconverter.hpp"

#include <string>

/*In: double value of dollars
 *Out: Euro value of input dollars as of 19.10.14
 */
double dollarToEuroConverter::convert(double inputDollars){
  return inputDollars*0.78224;
}

std::string dollarToEuroConverter::toString() const{
  return "Dollar to Euro Converter";
}


converter *dollarToEuroConverter::create()
{
    return new dollarToEuroConverter;
}