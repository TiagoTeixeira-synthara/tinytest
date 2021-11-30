#ifndef unit_test_h
#define unit_test_h

#ifdef __cplusplus
#	include <cstdio>
#	include <chrono>
#else
#	include <stdio.h>
#	include <time.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef UNITTEST_TIMEMICRO
#	ifdef __cplusplus
	unsigned long long unittest_timemicro() { return std::chrono::duration_cast<std::chrono::microseconds>( std::chrono::high_resolution_clock::now().time_since_epoch() ).count(); }
#	else
	unsigned long long unittest_timemicro() { struct timespec ts; timespec_get(&ts, TIME_UTC); return (ts.tv_sec * 1000000000L + ts.tv_nsec) * 0.001; }
#	endif
#endif

#define UNITTEST_XSTR(TXT) #TXT
#define UNITTEST_STR(TXT) UNITTEST_XSTR(TXT)

#define UNITTEST_PRINT(WHAT, ...) fprintf(stdout, WHAT, __VA_ARGS__);
#define UNITTEST_FILNUM __FILE__ ":" UNITTEST_STR(__LINE__)
#define UNITTEST_PRINTARG()

#define UNITTEST_SUCCESS() ++test_count_passed
#define UNITTEST_FAILURE() 

#define UNITTEST_CASE_BEGIN() ++test_count_all

#define UNITTEST_INIT() unsigned int unittest_all = 0, unittest_passed = 0;

// Assertions

#define UNITTEST_ASSERT_TRUE(STATEMENT) \
	UNITTEST_CASE_BEGIN(); \
	if (STATEMENT) UNITTEST_SUCCESS(); \
	else { UNITTEST_FAILURE(); UNITTEST_PRINT(UNITTEST_FILNUM " -> test case FAILED: got FALSE instead of TRUE\r\n"); }

#define UNITTEST_ASSERT_FALSE(STATEMENT) \
	UNITTEST_CASE_BEGIN(); \
	if (!(STATEMENT)) UNITTEST_SUCCESS(); \
	else { UNITTEST_FAILURE(); UNITTEST_PRINT(UNITTEST_FILNUM " -> test case FAILED: got TRUE instead of FALSE\r\n"); }

#define UNITTEST_ASSERT_FLOAT_EQUAL(STATEMENT, EXPECTED) \
	UNITTEST_CASE_BEGIN(); \
	if (STATEMENT == EXPECTED) UNITTEST_SUCCESS(); \
	else { UNITTEST_FAILURE(); UNITTEST_PRINT(UNITTEST_FILNUM " -> test case FAILED: got %f instead of %f \r\n", STATEMENT, EXPECTED); }

#define UNITTEST_ASSERT_EQUAL(STATEMENT, EXPECTED) \
	UNITTEST_CASE_BEGIN(); \
	if (STATEMENT == EXPECTED) UNITTEST_SUCCESS(); \
	else { UNITTEST_FAILURE(); UNITTEST_PRINT(UNITTEST_FILNUM " -> test case FAILED: arguments are different \r\n"); }

#define UNITTEST_ASSERT_INT_EQUAL(STATEMENT, EXPECTED) \
	UNITTEST_CASE_BEGIN(); \
	if (STATEMENT == EXPECTED) UNITTEST_SUCCESS(); \
	else { UNITTEST_FAILURE(); UNITTEST_PRINT(UNITTEST_FILNUM " -> test case FAILED: got %d instead of %d \r\n", STATEMENT, EXPECTED); }

#define UNITTEST_ASSERT_CSTR_EQUAL(STATEMENT, EXPECTED) \
	UNITTEST_CASE_BEGIN(); \
	if (strcmp(STATEMENT, EXPECTED) == 0) UNITTEST_SUCCESS(); \
	else { UNITTEST_FAILURE(); UNITTEST_PRINT(UNITTEST_FILNUM " -> test case FAILED: got %s instead of %s \r\n", STATEMENT, EXPECTED); }

#define UNITTEST_ASSERT_TIME_NOTLONGER_BEGIN UNITTEST_CASE_BEGIN(); test_tim = unittest_timemicro();
#define UNITTEST_ASSERT_TIME_NOTLONGER_END(MICROS) if (unittest_timemicro() - test_tim > MICROS) \
	{ UNITTEST_FAILURE(); UNITTEST_PRINT(UNITTEST_FILNUM " -> test case FAILED: code execution took %lluus while max was %lluus\r\n", unittest_timemicro() - test_tim, MICROS ) } else UNITTEST_SUCCESS(); test_tim = 0;

#ifdef __cplusplus
#	define UNITTEST_ASSERT_NOEXCEPTION_START UNITTEST_CASE_BEGIN(); try {
#	define UNITTEST_ASSERT_NOEXCEPTION_END } catch(std::exception &e) { test_exc = 1; UNITTEST_FAILURE(); UNITTEST_PRINT(UNITTEST_FILNUM " -> test case FAILED: an exception occurred: %s\r\n", e.what()); } \
											   catch(...) { test_exc = 1; UNITTEST_FAILURE(); UNITTEST_PRINT(UNITTEST_FILNUM " -> test case FAILED: an exception occurred\r\n"); } \
											   if ( test_exc == 0 ) UNITTEST_SUCCESS(); test_exc = 0;

#	define UNITTEST_ASSERT_THROWEXCEPTION_START UNITTEST_CASE_BEGIN(); try {
#	define UNITTEST_ASSERT_THROWEXCEPTION_END } catch(...) { test_exc = 1; UNITTEST_SUCCESS(); } \
											   if ( test_exc == 0 ) { UNITTEST_FAILURE(); UNITTEST_PRINT(UNITTEST_FILNUM " -> test case FAILED: no exception was thrown\r\n"); } test_exc = 0;

#endif

// Assertions end


// Unit test declaration

#define UNITTEST_SETUP() unsigned long long test_tim = 0; int test_exc = 0; int test_count_all = 0; int test_count_passed = 0;

#define UNITTEST_BEGIN(NAME) int test_##NAME()

#define UNITTEST_END() do { UNITTEST_PRINT("Test complete\r\n%d cases passed\r\n%d cases failed\r\n\r\n", test_count_passed, test_count_all - test_count_passed); return test_count_all == test_count_passed; } while (0)

// Unit test declaration end


// Unit test runblock

#define UNITTEST_RUNBLOCK_BEGIN() UNITTEST_PRINT("\r\nBeginning tests\r\n\r\n")

#define UNITTEST_EXEC(NAME) do { UNITTEST_PRINT("Running test \"" UNITTEST_STR(NAME) "\"\r\n") ++unittest_all; unittest_passed += test_##NAME(); } while(0)

#define UNITTEST_RUNBLOCK_END() do {\
		if (unittest_all == unittest_passed) { UNITTEST_PRINT("All %d tests complete SUCCESSFULLY\r\n\r\n", unittest_all); return 0; } \
		else { UNITTEST_PRINT("All %d tests complete\r\nSuccessful: %d\r\nFailed: %d\r\n\r\n", unittest_all, unittest_passed, unittest_all - unittest_passed); return 1; } \
	} while(0)

// Unit test runblock end

#ifdef __cplusplus
}
#endif

#endif
