/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT()) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

/*=======Automagically Detected Files To Include=====*/
#ifdef __WIN32__
#define UNITY_INCLUDE_SETUP_STUBS
#endif
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "Types.h"
#include "defines.h"
#include "data_handler.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_ParseEndPointFromUrl_should_know_invalid_url();
extern void test_ParseEndPointFromUrl_should_be_create_terminal();
extern void test_ParseEndPointFromUrl_should_be_get_terminal();
extern void test_ParseEndPointFromUrl_should_be_get_terminal_list();
extern void test_ParseTerminalInfo_return_failure_for_crap_data();
extern void test_ParseTerminalInfo_support_all_types();
extern void test_ParseTerminalInfo_support_partial_types();
extern void test_SerializeTerminalDetails_should_get_correct_json_data_with_no_transaction();
extern void test_SerializeTerminalDetails_should_get_correct_json_data_with_transaction();


/*=======Suite Setup=====*/
static void suite_setup(void)
{
#if defined(UNITY_WEAK_ATTRIBUTE) || defined(UNITY_WEAK_PRAGMA)
  suiteSetUp();
#endif
}

/*=======Suite Teardown=====*/
static int suite_teardown(int num_failures)
{
#if defined(UNITY_WEAK_ATTRIBUTE) || defined(UNITY_WEAK_PRAGMA)
  return suiteTearDown(num_failures);
#else
  return num_failures;
#endif
}

/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


/*=======MAIN=====*/
int main(void)
{
  suite_setup();
  UnityBegin("./test_data_handler.c");
  RUN_TEST(test_ParseEndPointFromUrl_should_know_invalid_url, 16);
  RUN_TEST(test_ParseEndPointFromUrl_should_be_create_terminal, 23);
  RUN_TEST(test_ParseEndPointFromUrl_should_be_get_terminal, 30);
  RUN_TEST(test_ParseEndPointFromUrl_should_be_get_terminal_list, 37);
  RUN_TEST(test_ParseTerminalInfo_return_failure_for_crap_data, 44);
  RUN_TEST(test_ParseTerminalInfo_support_all_types, 56);
  RUN_TEST(test_ParseTerminalInfo_support_partial_types, 76);
  RUN_TEST(test_SerializeTerminalDetails_should_get_correct_json_data_with_no_transaction, 96);
  RUN_TEST(test_SerializeTerminalDetails_should_get_correct_json_data_with_transaction, 114);

  return suite_teardown(UnityEnd());
}