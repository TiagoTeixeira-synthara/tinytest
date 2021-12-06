#define _CRT_SECURE_NO_WARNINGS 1

#include "lib/unittest.h"

#include <string>

/**
 * @file functions.cpp This file contains simple functions to be tested
 */

// This file utilizes trap tests, in order to use them, trap must be linked to this file. This trap is defined in tests.cpp file.
UNITTEST_TRAP_LINK(trap1);

double mul(double a, double b)
{
    return a * b;
}

double sq(double n)
{
    return mul(n, n);
}

void numtxt(char* txt, int n)
{
    sprintf(txt, "%d", n);
}

void trapfunc()
{
    UNITTEST_TRAP_ACTIVATE(trap1);
}

void traptest(unsigned int begin, unsigned int end, unsigned int hit)
{
    for (unsigned int i = begin; i <= end; ++i)
    {
        if (i == hit)
            trapfunc();
    }
}

void traptest2(unsigned int begin, unsigned int end, unsigned int hit)
{
    for (unsigned int i = begin; i <= end; ++i)
    {
        if (i > hit)
            trapfunc();
    }
}