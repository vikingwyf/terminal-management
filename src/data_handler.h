#ifdef _DATA_HANDLER_H_
#define _DATA_HANDLER_H_

eEndPoint ParseEndPointFromUrl(char* url, int* param);

//! Parse json data to get terminal's supported card types and transaction types.
//! pJson - input, json data which contains terminal info of card types and transaction types.
//! pSupportedCardTypes - output, get supported card types
//! pSupportedTransactionTypes - output, get supported transaction types.
//! return 0 - success, -1 failure.
int ParseTerminalInfo(
	char* pJson, 
	sCardTypes* pSupportedCardTypes,
	sTransactionTypes* pSupportedTransactionTypes);
	
//! Serialize terminal details into JSON data.
//! pJson - output, Serialized json data.
//! pTerminal - input, terminal detais info.
void SerializeTerminalDetails(char** pJson, const sTerminal* pTerminal);

//! Serialize terminal create response into JSON data.
//! pJson - output, Serialized json data.
void SerializeTerminalCreateResponse(char** pJson, int id);

#endif // _DATA_HANDLER_H_
