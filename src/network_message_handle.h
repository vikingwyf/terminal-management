#ifdef _NETWORK_MESSAGE_HANDLER_H_
#define _NETWORK_MESSAGE_HANDLER_H_

#define I(X) X
#define STR(X) #X
#define XSTR(X) STR(X)
#define HostName "http:I(/)I(/)localhost/"

eEndPoint ParseEndPointFromUrl(char* url);

#endif // _NETWORK_MESSAGE_HANDLER_H_
