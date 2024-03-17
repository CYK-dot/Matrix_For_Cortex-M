#include "matrix_os_config.h"
RCS_MMU_T matrix_mmu;

void* OS_Malloc(uint8_t size_byte)
{
    #ifdef MALLOC_DISABLE
        return RCS_MMU_Malloc(&matrix_mmu,size_byte);
    #else
        return malloc(size_byte);
    #endif
}

void OS_Free(void* mem_p)
{
    #ifdef MALLOC_DISABLE
        RCS_MMU_Free(&matrix_mmu,mem_p);
    #else
        free(mem_p);
    #endif
}

void OS_Err_Collector(const char* format, ...)
{
	
}

void OS_Commander(const char* format, ...)
{
	
}
/* =======config function==================================*/
void OS_Matrix_Init(void)
{
    
}