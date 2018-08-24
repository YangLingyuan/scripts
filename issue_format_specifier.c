#include<stddef.h>
#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>
#include<stddef.h>
void execute_format_specifier()
{
    printf("***********************************************'\n");
    printf("Execute the issue of format specifier  --- Start!\n\n");
    char buffer[256];
    int ctx=0;
    int* my_ctx=&ctx;
    printf("The address been write to the buffer should be: 8-byte in 64-bit system and 4-bytes in 32-bit system\n");
    /*Make use of macro to make the format stay the same in both 32 and 64 bits system */
    snprintf(buffer, sizeof(buffer), "my_ctx: %" PRIuPTR  "", (uintptr_t)my_ctx);
    printf("The correct 64-bit implementation access address: %s \n",buffer);

    /*original version of format specifier which may not portable from 32-bit to 64-bit system*/
    snprintf(buffer, sizeof(buffer), "my_ctx: %u", (uint32_t)my_ctx);
    printf("The wrong 64-bit implementation access address: %s \n\n",buffer);

    printf("Execute the issue of format specifier --- End!\n");
    printf("***********************************************'\n\n");
}