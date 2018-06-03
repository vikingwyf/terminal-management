#include "terminal_management.h"
#include "defines.h"

static sTerminal terminals[100];
static int currentAvailableId = 0;

int AddeTerminal(sTransaction* pTransactions, int transactionNum)
{
	int allocatedId = currentAvailableId++;
	terminals[allocatedId].id = allocatedId;
	terminals[allocatedId].pTransactions = pTransactions;
	terminals[allocatedId].transactionNum = transactionNum;
	
	return allocatedId;
}

int GetTerminal(int id, sTransaction** pTransactions, int* transactionNum)
{
	if (id >= currentAvailableId)
	{
		return -1;
	}
	
	sTerminal terminal = terminals[id];
	*pTransactions = terminal.pTransactions;
	*transactionNum = terminal.transactionNum;
	
	return 0;
}
