#ifndef _END_POINTS_H_
#define _END_POINTS_H_

#include "microhttpd.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//! Provide the service to create a terminal on the server and send response to connection \a connection.
int handle_terminal_create(
	struct MHD_Connection* connection,
    const char* upload_data,
    size_t* upload_data_size);
    
//! Provide the end point service to get termainl info and send response to connection \a connection.    
int handle_terminal_read(
	struct MHD_Connection* connection,
    const char* upload_data,
    size_t* upload_data_size);

//! Provide the end point service to get the terminal list and send response to connection \a connection.
int handle_terminal_list_get(
	struct MHD_Connection* connection,
    const char* upload_data,
    size_t* upload_data_size);

#endif // _END_POINTS_H_
