#ifndef test_trap_h
#define test_trap_h

#include "functions.h"

#include "lib/unittest.h"

/**
 * @file test_trap.h This file contains trap tests examples
 */

// In order to use traps in files other than main test file, traps need to be linked using UNITTEST_TRAP_LINK macro
UNITTEST_TRAP_LINK(trap1);

UNITTEST_BEGIN(traptest)
{
    UNITTEST_SETUP();

    UNITTEST_ASSERT_TRAP_START(trap1);
    traptest(0, 100, 101);
    UNITTEST_ASSERT_TRAP_HIT_END(trap1);

    UNITTEST_ASSERT_TRAP_START(trap1);
    traptest(0, 100, 100);
    UNITTEST_ASSERT_TRAP_HIT_END(trap1);

    UNITTEST_ASSERT_TRAP_START(trap1);
    traptest(0, 100, 99);
    UNITTEST_ASSERT_TRAP_HIT_END(trap1);

    UNITTEST_END();
}

UNITTEST_BEGIN(traptest_nothit)
{
    UNITTEST_SETUP();

    UNITTEST_ASSERT_TRAP_START(trap1);
    traptest(0, 100, 101);
    UNITTEST_ASSERT_TRAP_NOT_HIT_END(trap1);

    UNITTEST_ASSERT_TRAP_START(trap1);
    traptest(10, 100, 9);
    UNITTEST_ASSERT_TRAP_NOT_HIT_END(trap1);

    UNITTEST_ASSERT_TRAP_START(trap1);
    traptest(0, 100, 99);
    UNITTEST_ASSERT_TRAP_NOT_HIT_END(trap1);

    UNITTEST_END();
}

UNITTEST_BEGIN(traptest_count)
{
    UNITTEST_SETUP();

    UNITTEST_ASSERT_TRAP_START(trap1);
    traptest2(0, 1000, 900);
    UNITTEST_ASSERT_TRAP_HIT_COUNT_END(trap1, 100);

    UNITTEST_ASSERT_TRAP_START(trap1);
    traptest2(0, 1000, 1500);
    UNITTEST_ASSERT_TRAP_HIT_COUNT_END(trap1, 100);

    UNITTEST_ASSERT_TRAP_START(trap1);
    traptest2(0, 1000, 500);
    UNITTEST_ASSERT_TRAP_HIT_COUNT_END(trap1, 100);

    UNITTEST_END();
}

UNITTEST_BEGIN(traptest_more)
{
    UNITTEST_SETUP();

    UNITTEST_ASSERT_TRAP_START(trap1);
    traptest2(0, 1000, 800);
    UNITTEST_ASSERT_TRAP_HIT_MORE_END(trap1, 100);

    UNITTEST_ASSERT_TRAP_START(trap1);
    traptest2(0, 1000, 950);
    UNITTEST_ASSERT_TRAP_HIT_MORE_END(trap1, 100);

    UNITTEST_END();
}

UNITTEST_BEGIN(traptest_less)
{
    UNITTEST_SETUP();

    UNITTEST_ASSERT_TRAP_START(trap1);
    traptest2(0, 1000, 800);
    UNITTEST_ASSERT_TRAP_HIT_LESS_END(trap1, 100);

    UNITTEST_ASSERT_TRAP_START(trap1);
    traptest2(0, 1000, 950);
    UNITTEST_ASSERT_TRAP_HIT_LESS_END(trap1, 100);

    UNITTEST_END();
}

#endif
