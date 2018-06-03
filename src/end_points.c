#include "end_points.h"

char sendBuf[100];

int handle_terminal_create(
	struct MHD_Connection* connection,
    const char* upload_data,
    size_t* upload_data_size)
{
	struct MHD_Response* response;
    int ret;

	// Deserialize terminal data
	
	// Store terminal
	
	// Send response 
	
	//char* sendBuf = (char*)malloc(20);
	
	memset(sendBuf, 0, 20);
	strcpy(sendBuf, "{'id':'100'}");
	
	printf("%s %d", sendBuf, strlen(sendBuf));
    response = MHD_create_response_from_buffer(strlen(sendBuf), (void*)sendBuf, MHD_RESPMEM_PERSISTENT);
    
    ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);
    return ret;
}

int handle_terminal_read(
	struct MHD_Connection* connection,
    const char* upload_data,
    size_t* upload_data_size)
{
	return 0;
}

int handle_terminal_list_get(
	struct MHD_Connection* connection,
    const char* upload_data,
    size_t* upload_data_size	)
{
	return 0;
}
