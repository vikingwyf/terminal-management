#include "network_message_handle.h"
#include "defines.h"

static char hostUrl[100] = {0};

// Get end point name from URL
eEndPoint ParseEndPointFromUrl(const char* url)
{
	// Todo : need to check host name as well
	
	if (strstr(url, "create_terminal"))
	{
		return eEndPoint_CreateTerminal;
	}
	
	if (strstr(url, "get_terminal"))
	{
		return eEndPoint_GetTerminal;
	}
	
	if (strstr(url, "get_list"))
	{
		return eEndPoint_GetTerminalList;
	}
	
	return eEndPoint_Invalid;
}
