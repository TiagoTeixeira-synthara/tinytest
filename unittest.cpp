#define _CRT_SECURE_NO_WARNINGS 1

#include "unittest.h"

#include <iostream>
#include <exception>

UNITTEST_INIT()

double mul(double a, double b)
{
    return a * b;
}

double sq(double n)
{
    return mul(n, n);
}

void numtxt(char *txt, int n)
{
    sprintf(txt, "%d", n);
}

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

UNITTEST_BEGIN(exctest)
{
    UNITTEST_SETUP();

    UNITTEST_ASSERT_NOEXCEPTION_START
        // no exception
    UNITTEST_ASSERT_NOEXCEPTION_END

    UNITTEST_ASSERT_NOEXCEPTION_START
        throw std::exception("asd");
    UNITTEST_ASSERT_NOEXCEPTION_END

    UNITTEST_ASSERT_NOEXCEPTION_START
        throw 42;
    UNITTEST_ASSERT_NOEXCEPTION_END

    UNITTEST_END();
}

UNITTEST_BEGIN(throwtest)
{
    UNITTEST_SETUP();

    UNITTEST_ASSERT_THROWEXCEPTION_START
        throw 42;
    UNITTEST_ASSERT_THROWEXCEPTION_END

    UNITTEST_ASSERT_THROWEXCEPTION_START
        throw std::exception("asd");
    UNITTEST_ASSERT_THROWEXCEPTION_END

    UNITTEST_ASSERT_THROWEXCEPTION_START
        
    UNITTEST_ASSERT_THROWEXCEPTION_END

    UNITTEST_END();
}

UNITTEST_BEGIN(timtest)
{
    UNITTEST_SETUP();

    UNITTEST_ASSERT_TIME_NOTLONGER_BEGIN
    volatile float n = 1.5;
    for (unsigned int i = 0; i < 10000000; ++i)
    {
        n *= n + 0.5;
    }
    UNITTEST_ASSERT_TIME_NOTLONGER_END(100)

    UNITTEST_ASSERT_TIME_NOTLONGER_BEGIN
    for (unsigned int i = 0; i < 100; ++i)
    {
        n *= n + 0.5;
    }
    UNITTEST_ASSERT_TIME_NOTLONGER_END(100)

    UNITTEST_END();
}

int main()
{
    std::cout << "Hello World!\n";

#ifdef UNITTEST
    UNITTEST_RUNBLOCK_BEGIN()

        UNITTEST_EXEC(multest);
        UNITTEST_EXEC(sqtest);
        UNITTEST_EXEC(txttest);
        UNITTEST_EXEC(exctest);
        UNITTEST_EXEC(throwtest);
        UNITTEST_EXEC(timtest);
    
    UNITTEST_RUNBLOCK_END();
#endif
}