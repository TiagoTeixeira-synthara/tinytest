# TINY TEST FRAMEWORK

Tiny test framework is small, header-only unit testing framework for C and C++ languages.
The goal of this project is to share fast and easy way to test your projects.

## Using the framework

To begin work with the framework, few steps has to be made:

1. Include "unittest.h" in your project
2. Call "UNITTEST_INIT()" macro once in your project in global scope
3. Add UNITTEST definition to your project to enable the tests

Once above steps are complete, you may create and execute unit tests using set of test macros.

## Test macros

Below are listed all testing macros this framework has to offer

Test name                                                            | Description
---------------------------------------------------------------------|-----------------
UNITTEST_ASSERT_TRUE(STATEMENT)                                      | Tests if STATEMENT evaluates to truth.
UNITTEST_ASSERT_FALSE(STATEMENT)                                     | Tests if STATEMENT evaluates to false.
UNITTEST_ASSERT_FLOAT_EQUAL_EPS(STATEMENT, EXPECTED, EPS)            | Compares single or double precision floating point STATEMENT with floating point EXPECTED using specified epsilon value EPS
UNITTEST_ASSERT_DOUBLE_EQUAL_EPS(STATEMENT, EXPECTED, EPS)           |
UNITTEST_ASSERT_FLOAT_EQUAL(STATEMENT, EXPECTED)                     | Compares single or double precision floating point STATEMENT with floating point EXPECTED using default system epsilon value
UNITTEST_ASSERT_DOUBLE_EQUAL(STATEMENT, EXPECTED)                    |
UNITTEST_ASSERT_EQUAL(STATEMENT, EXPECTED)                           | Compares two values STATEMENT and EXPECTED using simple == operator. This is best suited to use with structures and objects.
UNITTEST_ASSERT_INT_EQUAL(STATEMENT, EXPECTED)                       | Compares two values STATEMENT and EXPECTED using simple == operator and attempt to print their values upon failure as integers.
UNITTEST_ASSERT_CSTR_EQUAL(STATEMENT, EXPECTED)                      | Compares two c-strings STATEMENT and EXPECTED
UNITTEST_ASSERT_TIME_BEGIN()                                         | Begin time-based assertion block
UNITTEST_ASSERT_TIME_NOTLONGER_END(MICROS)                           | Asserts that code executed between UNITTEST_ASSERT_TIME_BEGIN and UNITTEST_ASSERT_TIME_NOTLONGER_END macros took no longer than MICROS microseconds
UNITTEST_ASSERT_TRAP_START(TRAPNAME)                                 | Begin trap-based assertion block and later assert that code between UNITTEST_ASSERT_TRAP_START and any of UNITTEST_ASSERT_TRAP_* macros hit specified trap TRAPNAME correct number of times
UNITTEST_ASSERT_TRAP_HIT_END(TRAPNAME)                               | Trap must be hit any number of times
UNITTEST_ASSERT_TRAP_NOT_HIT_END(TRAPNAME)                           | Trap must not be hit
UNITTEST_ASSERT_TRAP_HIT_COUNT_END(TRAPNAME, HITCOUNT)               | Trap must be hit specified number of times
UNITTEST_ASSERT_TRAP_HIT_MORE_END(TRAPNAME, HITCOUNT)                | Trap must be hit more than specified number of times
UNITTEST_ASSERT_TRAP_HIT_LESS_END(TRAPNAME, HITCOUNT)                | Trap must be hit less than specified number of times
UNITTEST_ASSERT_EXCEPTION_START                                      | Begin exception-based assertion block - this is only available when using C++ language
UNITTEST_ASSERT_NOEXCEPTION_END                                      | Assert that no exception occurred between UNITTEST_ASSERT_EXCEPTION_START and UNITTEST_ASSERT_NOEXCEPTION_END macros
UNITTEST_ASSERT_THROWEXCEPTION_END                                   | Assert that any exception occurred between UNITTEST_ASSERT_EXCEPTION_START and UNITTEST_ASSERT_THROWEXCEPTION_END macros
UNITTEST_ASSERT_EXCEPTIONTYPE_END(TYPE)                              | Assert that an exception of TYPE type occurred between UNITTEST_ASSERT_EXCEPTION_START and UNITTEST_ASSERT_THROWEXCEPTION_END macros

## Creating tests

Tests are created using a set of macros with syntax resembling function syntax. In order to create unit test, use UNITTEST_BEGIN(TESTNAME) macro, where TESTNAME will be name used to reference the test.
Inside the unit test function, testing code must be placed between UNITTEST_SETUP(); and UNITTEST_END(); macros.

Example test:

    UNITTEST_BEGIN(multest)
    {
        UNITTEST_SETUP();

        UNITTEST_ASSERT_EQUAL(mul(1.0, 5.0), 1.0 * 5.0);
        UNITTEST_ASSERT_EQUAL(mul(2.0, 3.0), 2.0 * 3.0);
        UNITTEST_ASSERT_EQUAL(mul(5.0, 7.0), 1.0);

        UNITTEST_END();
    }

## Trap tests

Traps are used to determine if a fragment of code was executed. In order to use trap tests, traps must be first defined using UNITTEST_TRAP_DEFINE(TRAPNAME) macro. Once trap is defined, it has to be linked 
in the file where testing function is present using UNITTEST_TRAP_LINK(TRAPNAME) macro and executed in desired line of code using UNITTEST_TRAP_ACTIVATE(TRAPNAME) macro.

## Test execution

In order to execute tests, begin test execution block using UNITTEST_RUNBLOCK_BEGIN() and UNITTEST_RUNBLOCK_END() macros and place a set of UNITTEST_EXEC(TESTNAME) macros for each test that is needed to run 
where TESTNAME is name of the test specified in UNITTEST_BEGIN(TESTNAME) macro.

## Examples

For more examples take a look at unittest.cpp file.