#include "unity.h"
#include "defines.h"
#include "network_message_handle.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_ParseEndPointFromUrl_should_know_invalid_url()
{
    eEndPoint endPoint = ParseEndPointFromUrl("http://localhost:8000/api/foo");

    TEST_ASSERT_EQUAL_INT(eEndPoint_Invalid, endPoint);
}

void test_ParseEndPointFromUrl_should_be_create_terminal()
{
    eEndPoint endPoint = ParseEndPointFromUrl("http://localhost:8000/api/create_terminal");

    TEST_ASSERT_EQUAL_INT(eEndPoint_CreateTerminal, endPoint);
}

void test_ParseEndPointFromUrl_should_be_get_terminal()
{
    eEndPoint endPoint = ParseEndPointFromUrl("http://localhost:8000/api/get_terminal");

    TEST_ASSERT_EQUAL_INT(eEndPoint_GetTerminal, endPoint);
}

void test_ParseEndPointFromUrl_should_be_get_terminal_list()
{
    eEndPoint endPoint = ParseEndPointFromUrl("http://localhost:8000/api/get_list");

    TEST_ASSERT_EQUAL_INT(eEndPoint_GetTerminalList, endPoint);
}
