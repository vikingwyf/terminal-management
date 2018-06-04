#ifndef _TERMINAL_MANAGER_H_
#define _TERMINAL_MANAGER_H_
#include "defines.h"

void InitializeTerminalManager();

//! Create a new terminal
//! supportedCardTypes - input, supported card types.
//! supportedTransactionTypes - input, supported transation types.
//! Return id created for the new terminal. If creation failed -1 will be returned.
int AddTerminal(sCardTypes supportedCardTypes,	sTransactionTypes supportedTransactionTypes);

//! Get a terminal
//! id - input, terminal id.
//! pTerminal - output, pointer to terminal.
//! return 0 - success, -1 failure.
int GetTerminal(int id, sTerminal* pTerminal); 

//! Get a terminal transactions
//! id - input, terminal id.
//! pTransactions - output, transactions of the terminal.
//! return 0 - success, -1 failure.
int GetTerminalTransactions(int id, sTransactions* pTransactions); 

//! Add transactions to a terminal
//! id - input, terminal id.
//! transactions - input, transactions to add.
//! return 0 - success, -1 failure.
int AddTermainTransactions(int id, sTransactions transactions);
  
    
#endif //_TERMINAL_MANAGER_H_
