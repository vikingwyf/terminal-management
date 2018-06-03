#ifndef _TERMINAL_MANAGEMENT_H_
#define _TERMINAL_MANAGEMENT_H_
#include "defines.h"

//! Create a new terminal with its transaction list pointer \a pTransactions and transaction number
//! Return id created for the new terminal. If creation failed -1 will be returned.
int AddeTerminal(sTransaction* pTransactions, int transactionNum);

//! Get transaction details for terminal \a id. 
int GetTerminal(int id, sTransaction** pTransactions, int* transactionNum); 
  
    
#endif //_TERMINAL_MANAGEMENT_H_
