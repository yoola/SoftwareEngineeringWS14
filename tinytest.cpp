#include <stdlib.h>
#include <stdio.h>

#include "tinytest.h"
#include "dollartoeuroconverter.hpp"
#include "TemperatureConverter.hpp"

const double eps = 1e-15;

// Relative compare
bool cmp(double value, double target)
{
    if (target == 0)
        return (abs(value) < eps);
    else
        return (abs(value/target - 1) < eps);
}

int testDollarToEuro(void)
{
    dollarToEuroConverter myConverter;
    TINYTEST_ASSERT(cmp(myConverter.convert(120), 93.8688));
    TINYTEST_ASSERT(cmp(myConverter.convert(0), 0));
    TINYTEST_ASSERT(cmp(myConverter.convert(10000), 7822.4));
    return 1; // Always return a value different than 0 at test end.
}


int testCelsiusToFahrenheit(void)
{
    CelsiusToFahrenheitConverter myConverter;
    TINYTEST_ASSERT(cmp(myConverter.convert(-10), 14));
    TINYTEST_ASSERT(cmp(myConverter.convert(0), 32));
    TINYTEST_ASSERT(cmp(myConverter.convert(32), 89.6));
    return 1; // Always return a value different than 0 at test end.
}


int testFahrenheitToCelsius(void)
{
    FahrenheitToCelsiusConverter myConverter;
    TINYTEST_ASSERT(cmp(myConverter.convert(-17), -27.2222));
    TINYTEST_ASSERT(cmp(myConverter.convert(32), 0));
    TINYTEST_ASSERT(cmp(myConverter.convert(34.7), 94.46));
    return 1; // Always return a value different than 0 at test end.
}

int testKelvinToCelsius(void)
{
    KelvinToCelsiusConverter myConverter;
    TINYTEST_ASSERT(cmp(myConverter.convert(0.5), -272.65));
    TINYTEST_ASSERT(cmp(myConverter.convert(55.5), -217.65));
    TINYTEST_ASSERT(cmp(myConverter.convert(300), 26.85));
    return 1; // Always return a value different than 0 at test end.
}


TINYTEST_START_SUITE(SimpleSuite);
TINYTEST_ADD_TEST(testDollarToEuro);
TINYTEST_ADD_TEST(testCelsiusToFahrenheit);
TINYTEST_ADD_TEST(testFahrenheitToCelsius);
TINYTEST_ADD_TEST(testKelvinToCelsius);
TINYTEST_END_SUITE();

TINYTEST_MAIN_SINGLE_SUITE(SimpleSuite);
