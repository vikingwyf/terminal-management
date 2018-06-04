#include "data_handler.h"
#include "defines.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

static char hostUrl[100] = {0};

// Get end point name from URL
eEndPoint ParseEndPointFromUrl(const char* url, int* param)
{
	// Todo : need to check host name as well
	
	if (strstr(url, "create_terminal"))
	{
		return eEndPoint_CreateTerminal;
	}
	
	if (strstr(url, "get_terminal"))
	{
		*param = atoi(strrchr(url, '/') + 1);
		return eEndPoint_GetTerminal;
	}
	
	if (strstr(url, "get_list"))
	{
		return eEndPoint_GetTerminalList;
	}
	
	return eEndPoint_Invalid;
}

// Helper function to remove spaces from a string.
void RemoveSpaces(char* string)
{
	char* i = string;
	char* j = string;
	while(*j != 0)
	{
		*i = *j++;
		if(*i != ' ')
		  	i++;
	}
	*i = 0;
}

int ParseTerminalInfo(
	char* pJson, 
	sCardTypes* pSupportedCardTypes,
	sTransactionTypes* pSupportedTransactionTypes)
{
	// Remove spaces.
	RemoveSpaces(pJson);
	
	// Find the card types
	char* cardTypePos = strstr(pJson, "\"cardType\"");
	if (cardTypePos != NULL)
	{
		cardTypePos += strlen("\"cardType\""); 
		if ((*cardTypePos++ == ':') && (*cardTypePos++ == '['))
		{
			char* cardTypeEndPos = strchr(cardTypePos, ']');
			char* pFound = strstr(cardTypePos, "\"Visa\"");
			if (pFound != NULL && pFound < cardTypeEndPos)
			{
				pSupportedCardTypes->supportVisa = 1;
			}
			pFound = strstr(cardTypePos, "\"MasterCard\"");
			if (pFound != NULL && pFound < cardTypeEndPos)
			{
				pSupportedCardTypes->supportMasterCard = 1;
			}
			pFound = strstr(cardTypePos, "\"EFTPOS\"");
			if (pFound != NULL && pFound < cardTypeEndPos)
			{
				pSupportedCardTypes->supportEfpos = 1;
			}	
		}
		else
		{
			return -1;
		}		
	}
	else
	{
		return -1;
	}
	
	// Find the transaction types
	char* transactionTypePos = strstr(pJson, "\"TransactionType\"");
	if (transactionTypePos != NULL)
	{
		transactionTypePos += strlen("\"TransactionType\""); 
		if ((*transactionTypePos++ == ':') && (*transactionTypePos++ == '['))
		{
			char* transactionTypeEndPos = strchr(transactionTypePos, ']');
			char* pFound = strstr(cardTypePos, "\"Cheque\"");
			if (pFound != NULL && pFound < transactionTypeEndPos)
			{
				pSupportedTransactionTypes->supportCheque = 1;
			}
			pFound = strstr(cardTypePos, "\"Savings\"");
			if (pFound != NULL && pFound < transactionTypeEndPos)
			{
				pSupportedTransactionTypes->supportSavings = 1;
			}
			pFound = strstr(cardTypePos, "\"Credit\"");
			if (pFound != NULL && pFound < transactionTypeEndPos)
			{
				pSupportedTransactionTypes->supportCredit = 1;
			}	
		}	
		else
		{
			return -1;
		}	
	}
	else
	{
		return -1;
	}
	
	return 0;
}

void SerializeTerminalDetails(char** pJson, const sTerminal* pTerminal)
{
	assert(*pJson);
	char* pStr = *pJson;
	
	// JSON start
	strcpy(pStr, "{");
	
	// Convert terminal id to a string
	char idStr[10] = {0};
	itoa(pTerminal->id, idStr, 10);

	// Fill terminal id
	strcat(pStr, "\"terminalID\":");
	strcat(pStr, idStr);
	strcat(pStr, ",");
	
	// Fill transactions
	strcat(pStr, "\"transactions\":[");
	int transactionNum = pTerminal->transactions.number;
	int i = 0;
	for (; i < transactionNum; i++)
	{
		if (i != 0)
		{
			strcat(pStr, ",");
		}
		strcat(pStr, "{");
		
		// card type
		strcat(pStr, "\"cardType\":");
		switch (pTerminal->transactions.transactions[i].cardType)
		{
			case eCardType_Visa:
				strcat(pStr, "\"Visa\",");
				break;
				
			case eCardType_MasterCard:
				strcat(pStr, "\"MasterCard\",");
				break;	
				
			case eCardType_EFTPOS:
				strcat(pStr, "\"EFTPOS\",");
				break;
				
			default:
				break;
		}
		// transaction type
		strcat(pStr, "\"TransactionType\":");
		switch (pTerminal->transactions.transactions[i].transactionType)
		{
			case eTransactionType_Cheque:
				strcat(pStr, "\"Cheque\"");
				break;
				
			case eTransactionType_Savings:
				strcat(pStr, "\"Savings\"");
				break;	
				
			case eTransactionType_Credit:
				strcat(pStr, "\"Credit\"");
				break;
				
			default:
				break;
		}
		
		strcat(pStr, "}");
	}
	strcat(pStr, "]");
	
	// JSON End
	strcat(pStr, "}");
	
	printf("%s\n", pStr);
}

void SerializeTerminalCreateResponse(char** pJson, int id)
{
	char idStr[10] = {0};
	itoa(id, idStr, 10);
	
    strcpy(*pJson, "{\"id\":\"");
    strcat(*pJson, idStr);
	strcat(*pJson, "\"}");
}
