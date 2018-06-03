#include "terminal_management.h"
#include "network_message_handle.h"
#include "end_points.h"
#include "defines.h"

int handle_received_request(
    void* cls,
    struct MHD_Connection* connection,
    const char* url,
    const char* method,
    const char* version,
    const char* upload_data,
    size_t* upload_data_size,
    void** ptr)
{
    (void)cls;
    int ret = -1;

	eEndPoint ep = ParseEndPointFromUrl(url);
	switch (ep)
	{
		case eEndPoint_CreateTerminal:
			if (strcmp(method, "POST"))
			{
				ret = handle_terminal_create(connection, upload_data, upload_data_size);
			}
			break;
		
		case eEndPoint_GetTerminal:
			if (strcmp(method, "GET"))
			{
				ret = handle_terminal_read(connection, upload_data, upload_data_size);
			}
			break;
			
		case eEndPoint_GetTerminalList:
			if (strcmp(method, "GET"))
			{
				ret = handle_terminal_list_get(connection, upload_data, upload_data_size);
			}
			break;
			
		default:
			printf("");
			break;		
	}

    *ptr = NULL;       /* clear context pointer */
    return ret;
}

int main(int argc, char** argv)
{
    struct MHD_Daemon* d;
        
    d = MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION, 80, NULL, NULL, &handle_received_request, NULL, MHD_OPTION_END);
    if (d == NULL)
        return 1;
        
    (void)getc(stdin);
    MHD_stop_daemon(d);
    return 0;
}
