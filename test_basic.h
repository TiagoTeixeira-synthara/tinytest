#ifndef test_basic_h
#define test_basic_h

#include "functions.h"

#include "lib/unittest.h"

#include <string>

/**
 * @file test_basic.h This file contains basic tests examples
 */

UNITTEST_BEGIN(multest)
{
    UNITTEST_SETUP();

    UNITTEST_ASSERT_EQUAL(mul(1.0, 5.0), 1.0 * 5.0);
    UNITTEST_ASSERT_EQUAL(mul(2.0, 3.0), 2.0 * 3.0);
    UNITTEST_ASSERT_EQUAL(mul(5.0, 7.0), 1.0);

    UNITTEST_END();
}

UNITTEST_BEGIN(sqtest)
{
    UNITTEST_SETUP();

    for (unsigned int i = 0; i < 100; ++i)
    {
        UNITTEST_ASSERT_FLOAT_EQUAL(sq((double)i), (double)i * (double)i);
    }

    UNITTEST_ASSERT_FLOAT_EQUAL(sq(5.0), 25.0);
    UNITTEST_ASSERT_FLOAT_EQUAL(sq(25.0), 25.0 * 25.0);
    UNITTEST_ASSERT_FLOAT_EQUAL(sq(0), 0);
    UNITTEST_ASSERT_FLOAT_EQUAL(sq(1000), 1000 * 1000);
    UNITTEST_ASSERT_FLOAT_EQUAL(sq(3), 1);

    UNITTEST_END();
}

UNITTEST_BEGIN(txttest)
{
    UNITTEST_SETUP();

    char txt[5];

    numtxt(txt, 1);
    UNITTEST_ASSERT_CSTR_EQUAL(txt, "1");

    numtxt(txt, 123);
    UNITTEST_ASSERT_CSTR_EQUAL(txt, "123");

    numtxt(txt, 7);
    UNITTEST_ASSERT_CSTR_EQUAL(txt, "7");

    UNITTEST_END();
}

UNITTEST_BEGIN(timtest)
{
    UNITTEST_SETUP();

    UNITTEST_ASSERT_TIME_BEGIN();
    volatile float n = 1.5;
    for (unsigned int i = 0; i < 10000000; ++i)
    {
        n *= n + 0.5;
    }
    UNITTEST_ASSERT_TIME_NOTLONGER_END(100)

    UNITTEST_ASSERT_TIME_BEGIN();
    for (unsigned int i = 0; i < 100; ++i)
    {
        n *= n + 0.5;
    }
    UNITTEST_ASSERT_TIME_NOTLONGER_END(100)

    UNITTEST_END();
}

#endif