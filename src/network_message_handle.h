#ifdef _NETWORK_MESSAGE_HANDLER_H_
#define _NETWORK_MESSAGE_HANDLER_H_

#define I(X) X
#define STR(X) #X
#define XSTR(X) STR(X)
#define HostName "http:I(/)I(/)localhost/"

eEndPoint ParseEndPointFromUrl(char* url);

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

#endif // _NETWORK_MESSAGE_HANDLER_H_
