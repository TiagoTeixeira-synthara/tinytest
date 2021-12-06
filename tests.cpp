#include "tests.h"

#include "test_basic.h"
#include "test_exceptions.h"
#include "test_trap.h"

#include "lib/unittest.h"

/**
 * @file tests.c This is main test file used to execute all defined unit tests.
 */

// Initialize unit testing framework - this must be done exactly once in the project
UNITTEST_INIT()

// Define trap used in test_trap.h tests
UNITTEST_TRAP_DEFINE(trap1);

#ifdef UNITTEST
void runTests()
{
UNITTEST_RUNBLOCK_BEGIN();

UNITTEST_EXEC(multest);
UNITTEST_EXEC(sqtest);
UNITTEST_EXEC(txttest);
UNITTEST_EXEC(exctest);
UNITTEST_EXEC(throwtest);
UNITTEST_EXEC(throwtypetest);
UNITTEST_EXEC(timtest);
UNITTEST_EXEC(traptest);
UNITTEST_EXEC(traptest_nothit);
UNITTEST_EXEC(traptest_count);
UNITTEST_EXEC(traptest_more);
UNITTEST_EXEC(traptest_less);

UNITTEST_RUNBLOCK_END();
}
#endif
