/* ========.h head=====================================*/
#ifndef MATRIX_OS_SUPPORT_H_
#define MATRIX_OS_SUPPORT_H_

/* ========includes=====================================*/
#include "matrix_config.h"

/* ========interface funtion===============================*/
void* OS_Malloc(uint8_t size_byte)
{
    #if MALLOC_DISABLE
        return RTOS_Malloc(size_byte);
    #else
        return malloc(size_byte);
    #endif
}

void OS_Free(void* mem_p)
{
    #if MALLOC_DISABLE
        RTOS_Free(mem_p);
    #else
        free(mem_p);
    #endif
}

void OS_Err_Collector(char* err_string)
{
    printf(err_string);
}

void OS_Commander(char* command)
{
    
}

/* =======config function==================================*/
void OS_Matrix_Init(void)
{
    
}
#endif