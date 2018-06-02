#ifndef _DEFINES_H_
#define _DEFINES_H_

// Definition of card types
typedef enum 
{
	eCardType_Visa = 0,
	eCardType_MasterCard,
	eCardType_EFTPOS
} eCardType;

typedef enum 
{
	eTransactionType_Cheque = 0,
	eTransactionType_Saving,
	eTransactionType_Credit	
} eTransactionType;

typedef struct
{
	eCardType cardType;
	eTransactionType transactionType; 
} sTransaction;

typedef struct
{
	int id;
	int transactionNum;
	sTransaction* pTransactions;
} sTerminal;

typedef enum
{
	eEndPoint_CreateTerminal = 0,
	eEndPoint_GetTerminal,
	eEndPoint_GetTerminalList
} eEndPoint;

#endif // _DEFINES_H_
