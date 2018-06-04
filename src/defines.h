#ifndef _DEFINES_H_
#define _DEFINES_H_


#define InvalidTerminalId -1


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
	eTransactionType_Savings,
	eTransactionType_Credit	
} eTransactionType;

typedef struct
{
	eCardType cardType;
	eTransactionType transactionType; 
} sTransaction;

typedef struct
{
	sTransaction* transactions;
	int number;
} sTransactions;

typedef struct
{
	unsigned int supportVisa : 1;
	unsigned int supportMasterCard : 1;
	unsigned int supportEfpos : 1;
} sCardTypes;

typedef struct
{
	unsigned int supportCheque : 1;
	unsigned int supportSavings : 1;
	unsigned int supportCredit : 1;
} sTransactionTypes;

typedef struct
{
	int id;
	sCardTypes supportedCardTypes;
	sTransactionTypes supportedTransactionTypes; 
	sTransactions transactions;
} sTerminal;

typedef enum
{
	eEndPoint_Invalid = 0,
	eEndPoint_CreateTerminal,
	eEndPoint_GetTerminal,
	eEndPoint_GetTerminalList
} eEndPoint;

#endif // _DEFINES_H_
