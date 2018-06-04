#include "defines.h"
#include "end_points.h"
#include "terminal_manager.h"
#include "data_handler.h"

#define StatusCodeBad 400
#define SendBufferSize 1000

int handle_terminal_create(
	struct MHD_Connection* connection,
    const char* upload_data,
    size_t* upload_data_size)
{
	struct MHD_Response* response;
	unsigned int statusCode = MHD_HTTP_OK;
    int ret;
    
    char* data = (char*) malloc(SendBufferSize);
	memset(data, 0, SendBufferSize);
    
    if (upload_data == NULL)
	{
		statusCode == StatusCodeBad;
		strcpy(data, "invalid request");
		return -1;
	}
	else
	{
		// Deserialize terminal data
		sCardTypes supportedCardTypes;
		sTransactionTypes supportedTransactionTypes;
		ParseTerminalInfo(upload_data, &supportedCardTypes, &supportedTransactionTypes);
		
		// Store terminal
		int id = AddTerminal(supportedCardTypes, supportedTransactionTypes);
		
		// Serialize response data	
		SerializeTerminalCreateResponse(&data, 0);
	}

	// Send response 
    response = MHD_create_response_from_buffer(strlen(data), (void*)data, MHD_RESPMEM_PERSISTENT);
    
    ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);
    return ret;
}

int handle_terminal_read(struct MHD_Connection* connection,	int terminalId)
{
	char* data = (char*) malloc(SendBufferSize);
	memset(data, 0, SendBufferSize);
	
	// Get the terminal's details.
	sTerminal terminal;
	int ret = GetTerminal(terminalId, &terminal);
	if (ret != -1)
	{
		// Serialize data
		SerializeTerminalDetails(&data, &terminal);
	}
	else
	{
		strcpy(data, "invalid terminal id");
	}

	// Send response
	struct MHD_Response* response = MHD_create_response_from_buffer(strlen(data), (void*)data, MHD_RESPMEM_PERSISTENT);
    ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);
    return ret;
}

int handle_terminal_list_get(
	struct MHD_Connection* connection,
    const char* upload_data,
    size_t* upload_data_size)
{
	return 0;
}
