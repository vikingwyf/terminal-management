#ifndef _TERMINAL_MANAGEMENT_H_
#define _TERMINAL_MANAGEMENT_H_

#include "microhttpd.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int handle_create_terminal(
    const char* page,
    struct MHD_Connection* connection,
    const char* upload_data,
    size_t* upload_data_size);
    
    
#endif //_TERMINAL_MANAGEMENT_H_
