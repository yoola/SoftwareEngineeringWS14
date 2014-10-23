#include "dollartoeuroconverter.hpp"

int main()
{
    dollarToEuroConverter* myConverter = new dollarToEuroConverter();
    double aLotOfDollars = 10000;
    double aLotOfEuros = myConverter->convert(aLotOfDollars);
    std::cout << myConverter->toString() << " has converted "<< aLotOfDollars << " Dollar to " << aLotOfEuros <<" Euros!"<<std::endl;
    return 0;
}

