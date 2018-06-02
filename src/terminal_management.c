#include "terminal_management.h"
#include "defines.h"

sTerminal gTerminals[100];

int handle_create_terminal(
    const char* page,
    struct MHD_Connection* connection,
    const char* upload_data,
    size_t* upload_data_size)
{
    struct MHD_Response* response;
    int ret;

	// Deserialize terminal data
	
	// Store terminal
	
	// Send response 
	
	//char sendBuf[100];
    response = MHD_create_response_from_buffer(strlen(sendBuf), (void*)sendBuf, MHD_RESPMEM_PERSISTENT);
    ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);
    return ret;
}

