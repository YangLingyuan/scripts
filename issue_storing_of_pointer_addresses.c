#include<stddef.h>
#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>


void execute_storing_of_pointer_addresses()
{
    printf("*************************************************'\n");
	printf("Execute the issue of storing of pointer addresses --- Start!\n\n");
    uint32_t val=1;
    uint32_t * ptr=&val;
    printf("ptr=%p\n",ptr);
    uint32_t ptr_wrong=(uint32_t)ptr;
    printf("Storing pointer with wrong 64-bit implementation:0x%"PRIx32"\n",ptr_wrong);

    uintptr_t ptr_right=(uintptr_t)ptr;
    printf("Storing pointer with correct 64-bit implementation:0x%"PRIxPTR"\n",ptr_right);

	printf("Execute the issue of toring of pointer addresses --- End!\n");
	printf("***********************************************'\n\n");
}
