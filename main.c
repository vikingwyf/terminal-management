#include "terminal_management.h"
#include "network_message_handle.h"
#include "defines.h"

#define PAGE "{'id':'100'}"

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
    static int dummy;
    const char* page = cls;
    struct MHD_Response* response;
    int ret;
	
	eEndPoint ep = ParseEndPointFromUrl(url);
	switch (ep)
	{
		case eEndPoint_CreateTerminal:
			if (strcmp(method, "POST"))
			{
				handle_create_terminal(page, connection, upload_data, upload_data_size);
			}
			break;
		
		case eEndPoint_GetTerminal:
			
			break;
			
		case eEndPoint_GetTerminalList:
			
			break;
		default:
			break;		
	}

    *ptr = NULL;       /* clear context pointer */
//    response = MHD_create_response_from_buffer(strlen(page), (void*)page, MHD_RESPMEM_PERSISTENT);
//    ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
//    MHD_destroy_response(response);
    return ret;
}

int main(int argc, char** argv)
{
    struct MHD_Daemon* d;
    int port = 0;
    if (argc != 2)
    {
        port = 8000;
    }
    else
    {
    	port = atoi(argv[1]);
	}

    d = MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION, port, NULL, NULL, &handle_received_request, PAGE, MHD_OPTION_END);
    if (d == NULL)
        return 1;
        
    (void)getc(stdin);
    MHD_stop_daemon(d);
    return 0;
}
