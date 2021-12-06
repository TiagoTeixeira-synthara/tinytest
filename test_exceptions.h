#ifndef test_exceptions_h
#define test_exceptions_h

#include "lib/unittest.h"

#include <exception>

/**
 * @file test_exceptions.h This file contains exception tests examples
 */

UNITTEST_BEGIN(exctest)
{
    UNITTEST_SETUP();

    UNITTEST_ASSERT_EXCEPTION_START
        // no exception
    UNITTEST_ASSERT_NOEXCEPTION_END

    UNITTEST_ASSERT_EXCEPTION_START
        throw std::exception("asd");
    UNITTEST_ASSERT_NOEXCEPTION_END

    UNITTEST_ASSERT_EXCEPTION_START
        throw 42;
    UNITTEST_ASSERT_NOEXCEPTION_END

    UNITTEST_END();
}

UNITTEST_BEGIN(throwtest)
{
    UNITTEST_SETUP();

    UNITTEST_ASSERT_EXCEPTION_START
        throw 42;
    UNITTEST_ASSERT_THROWEXCEPTION_END

    UNITTEST_ASSERT_EXCEPTION_START
        throw std::exception("asd");
    UNITTEST_ASSERT_THROWEXCEPTION_END

    UNITTEST_ASSERT_EXCEPTION_START

    UNITTEST_ASSERT_THROWEXCEPTION_END

    UNITTEST_END();
}

UNITTEST_BEGIN(throwtypetest)
{
    UNITTEST_SETUP();

    UNITTEST_ASSERT_EXCEPTION_START
        throw 42;
    UNITTEST_ASSERT_EXCEPTIONTYPE_END(std::exception&)

    UNITTEST_ASSERT_EXCEPTION_START
        throw std::exception("asd");
    UNITTEST_ASSERT_EXCEPTIONTYPE_END(std::exception&)

    UNITTEST_END();
}

#endif
