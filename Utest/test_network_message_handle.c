#include "unity.h"
#include "foo.h"
#include "defines.h"
#include "network_message_handle.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_ParseEndPointFromUrl_get_correct_type()
{
    eEndPoint endPoint = ParseEndPointFromUrl();

    TEST_ASSERT_EQUAL_INT(eEndPoint_CreateTerminal, endPoint);
}
