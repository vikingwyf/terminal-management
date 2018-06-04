#include "unity.h"
#include "defines.h"
#include "terminal_manager.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_AddeTerminal_should_allocate_an_ID()
{
    sCardTypes supportedCardTypes;
	supportedCardTypes.supportVisa = 1;
	
	sTransactionTypes supportedTransactionTypes;
	supportedTransactionTypes.supportCheque = 1;
	
    TEST_ASSERT_NOT_EQUAL(-1, AddTerminal(supportedCardTypes, supportedTransactionTypes));
}

void test_GetTerminalTransactions_success()
{
	// Create a terminal	
	sCardTypes supportedCardTypes;
	supportedCardTypes.supportVisa = 1;
	
	sTransactionTypes supportedTransactionTypes;
	supportedTransactionTypes.supportCheque = 1;
	int id = AddTerminal(supportedCardTypes, supportedTransactionTypes);
	TEST_ASSERT_NOT_EQUAL(-1, id);
	
	// Add transactions
	sTransactions transactions;
	transactions.number = 2;
	transactions.transactions = (sTransaction*) malloc(transactions.number * sizeof(sTransaction));
	transactions.transactions[0].cardType = eCardType_Visa;
	transactions.transactions[0].transactionType = eTransactionType_Cheque;
	transactions.transactions[1].cardType = eCardType_MasterCard;
	transactions.transactions[1].transactionType = eTransactionType_Savings;
	AddTermainTransactions(id, transactions);
	
	// Get transactions
	sTransactions getTransactions;
	GetTerminalTransactions(id, &getTransactions);
	TEST_ASSERT_EQUAL_INT(eCardType_Visa, getTransactions.transactions[0].cardType);
	TEST_ASSERT_EQUAL_INT(eTransactionType_Cheque, getTransactions.transactions[0].transactionType);
	TEST_ASSERT_EQUAL_INT(eCardType_MasterCard, getTransactions.transactions[1].cardType);
	TEST_ASSERT_EQUAL_INT(eTransactionType_Savings, getTransactions.transactions[1].transactionType);
}
