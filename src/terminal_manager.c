#include "terminal_manager.h"
#include "defines.h"
#include <stdlib.h>
#include <string.h>

#define MaxTerminal 10000
static sTerminal terminals[MaxTerminal];
static int currentAvailableId = 0;

int AllocateTerminalID()
{
	return currentAvailableId == MaxTerminal ? -1 : currentAvailableId++;
}

int AddTerminal(sCardTypes supportedCardTypes,	sTransactionTypes supportedTransactionTypes)
{
	// Allocate an ID
	int allocatedId = AllocateTerminalID();
	if (allocatedId != -1)
	{
		terminals[allocatedId].id = allocatedId;
		terminals[allocatedId].supportedCardTypes = supportedCardTypes;
		terminals[allocatedId].supportedTransactionTypes = supportedTransactionTypes;
	}
	
	return allocatedId;
}

int GetTerminal(int id, sTerminal* pTerminal)
{
	if (id < 0 || id >= currentAvailableId)
	{
		return -1;
	}
	
	*pTerminal = terminals[id];
	return 0;
}

int GetTerminalTransactions(int id, sTransactions* pTransactions)
{
	if (id < 0 || id >= currentAvailableId)
	{
		return -1;
	}
	
	*pTransactions = terminals[id].transactions;
	return 0;
}

int AddTermainTransactions(int id, sTransactions transactions)
{
	if (id < 0 || id >= currentAvailableId)
	{
		return -1;
	}
	
	terminals[id].transactions = transactions;
	return 0;
}

void AddFakeTerminal()
{
	// Create a terminal	
	sCardTypes supportedCardTypes;
	supportedCardTypes.supportVisa = 1;
	sTransactionTypes supportedTransactionTypes;
	supportedTransactionTypes.supportCheque = 1;
	int id = AddTerminal(supportedCardTypes, supportedTransactionTypes);
	
	// Add transactions
	sTransactions transactions;
	transactions.number = 2;
	transactions.transactions = (sTransaction*) malloc(transactions.number * sizeof(sTransaction));
	transactions.transactions[0].cardType = eCardType_Visa;
	transactions.transactions[0].transactionType = eTransactionType_Cheque;
	transactions.transactions[1].cardType = eCardType_MasterCard;
	transactions.transactions[1].transactionType = eTransactionType_Savings;
	AddTermainTransactions(id, transactions);
}
void InitializeTerminalManager()
{
	AddFakeTerminal();
	AddFakeTerminal();
}
