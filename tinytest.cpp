#include <stdlib.h>
#include <stdio.h>

#include "tinytest.h"
#include "dollartoeuroconverter.hpp"
#include "TemperatureConverter.hpp"
#include "ShoeSizeConverter.hpp"

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
    TINYTEST_ASSERT(cmp(myConverter.convert(-3), 26.6));
    TINYTEST_ASSERT(cmp(myConverter.convert(32), 89.6));
    return 1; // Always return a value different than 0 at test end.
}


int testFahrenheitToCelsius(void)
{
    FahrenheitToCelsiusConverter myConverter;
    TINYTEST_ASSERT(cmp(myConverter.convert(-17), -27.2222));
    TINYTEST_ASSERT(cmp(myConverter.convert(1), -17.2222));
    TINYTEST_ASSERT(cmp(myConverter.convert(34.7), 1.5));
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

int testDEToUK(void)
{
    DEToUKConverter myConverter;
    TINYTEST_ASSERT(cmp(myConverter.convert(0), -25));
    TINYTEST_ASSERT(cmp(myConverter.convert(38.5), 5.31496));
    TINYTEST_ASSERT(cmp(myConverter.convert(45), 10.4331));
    return 1; // Always return a value different than 0 at test end.
}

int testDEToIT(void)
{
    DEToITConverter myConverter;
    TINYTEST_ASSERT(cmp(myConverter.convert(0), -1.005));
    TINYTEST_ASSERT(cmp(myConverter.convert(39), 37.9995));
    TINYTEST_ASSERT(cmp(myConverter.convert(50.5), 49.4995));
    return 1; // Always return a value different than 0 at test end.
}


TINYTEST_START_SUITE(SimpleSuite);
TINYTEST_ADD_TEST(testDollarToEuro);
TINYTEST_ADD_TEST(testCelsiusToFahrenheit);
TINYTEST_ADD_TEST(testFahrenheitToCelsius);
TINYTEST_ADD_TEST(testKelvinToCelsius);
TINYTEST_ADD_TEST(testDEToUK);
TINYTEST_ADD_TEST(testDEToIT);
TINYTEST_ADD_TEST(testConverterFactory);
TINYTEST_END_SUITE();

TINYTEST_MAIN_SINGLE_SUITE(SimpleSuite);
