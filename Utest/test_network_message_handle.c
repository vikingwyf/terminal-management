#include "unity.h"
#include "defines.h"
#include "network_message_handle.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

void test_ParseTerminalInfo_return_failure_for_crap_data()
{
	char crapData[] = "{xxx}";
	
	sCardTypes cardTypes;
	sTransactionTypes transactionTypes;
	
	int ret = ParseTerminalInfo(crapData, &cardTypes, &transactionTypes);

    TEST_ASSERT_EQUAL_INT(-1, ret);
}

void test_ParseTerminalInfo_support_all_types()
{
	char json[] = "{\"cardType\":[\"Visa\",\"MasterCard\",\"EFTPOS\"],\"TransactionType\": [\"Cheque\", \"Savings\", \"Credit\"]}";
	
	sCardTypes cardTypes;
	sTransactionTypes transactionTypes;
	
	int ret = ParseTerminalInfo(json, &cardTypes, &transactionTypes);
	
	TEST_ASSERT_EQUAL_INT(1, cardTypes.supportVisa);
	TEST_ASSERT_EQUAL_INT(1, cardTypes.supportMasterCard);
	TEST_ASSERT_EQUAL_INT(1, cardTypes.supportEfpos);
	
	TEST_ASSERT_EQUAL_INT(1, transactionTypes.supportCheque);
	TEST_ASSERT_EQUAL_INT(1, transactionTypes.supportSavings);
	TEST_ASSERT_EQUAL_INT(1, transactionTypes.supportCredit);

    TEST_ASSERT_EQUAL_INT(0, ret);
}

void test_ParseTerminalInfo_support_partial_types()
{
	char json[] = "{\"cardType\": [\"Visa\", \"EFTPOS\"], \"TransactionType\": [\"Cheque\", \"Credit\"]}";
	
	sCardTypes cardTypes = {0};
	sTransactionTypes transactionTypes = {0};
	
	int ret = ParseTerminalInfo(json, &cardTypes, &transactionTypes);
	
	TEST_ASSERT_EQUAL_INT(1, cardTypes.supportVisa);
	TEST_ASSERT_EQUAL_INT(0, cardTypes.supportMasterCard);
	TEST_ASSERT_EQUAL_INT(1, cardTypes.supportEfpos);
	
	TEST_ASSERT_EQUAL_INT(1, transactionTypes.supportCheque);
	TEST_ASSERT_EQUAL_INT(0, transactionTypes.supportSavings);
	TEST_ASSERT_EQUAL_INT(1, transactionTypes.supportCredit);

    TEST_ASSERT_EQUAL_INT(0, ret);
}

void test_SerializeTerminalDetails_should_get_correct_json_data_with_no_transaction()
{
	char* json = (char*) malloc (1000);
	memset(json, 0, 1000);
	char expectedJson[] = "{\"terminalID\":101,\"transactions\":[]}";
	
	sTerminal terminal;
	terminal.id = 101;
	terminal.transactions.number = 0;
	
	SerializeTerminalDetails(&json, &terminal);
	
	printf("%s", json);
	
	TEST_ASSERT_EQUAL_INT(0, strcmp(expectedJson, json));
}


void test_SerializeTerminalDetails_should_get_correct_json_data_with_transaction()
{
	char* json = (char*) malloc (1000);
	memset(json, 0, 1000);
	char expectedJson[] = "{\"terminalID\":101,\"transactions\":[{\"cardType\":\"Visa\",\"TransactionType\":\"Credit\"},{\"cardType\":\"EFTPOS\",\"TransactionType\":\"Savings\"}]}";
	
	sTerminal terminal;
	terminal.id = 101;
	terminal.transactions.number = 2;
	terminal.transactions.transactions = (sTransaction*) malloc(2 * sizeof(sTransaction));
	terminal.transactions.transactions[0].cardType = eCardType_Visa;
	terminal.transactions.transactions[0].transactionType = eTransactionType_Credit;
	terminal.transactions.transactions[1].cardType = eCardType_EFTPOS;
	terminal.transactions.transactions[1].transactionType = eTransactionType_Savings;
	
	SerializeTerminalDetails(&json, &terminal);
	
	printf("%s\n", expectedJson);
	
	TEST_ASSERT_EQUAL_INT(0, strcmp(expectedJson, json));
}
