#include <stddef.h>
#include <inttypes.h>
#include <stdio.h>
ptrdiff_t Get_element_wrong(uint8_t *array,int Index)
{
    intptr_t element=(intptr_t)(&(array[Index]));
    return element-(ptrdiff_t)array;
}

ptrdiff_t Get_element_correct(uint8_t *array,size_t Index)
{
    intptr_t element=(intptr_t)(&(array[Index]));
    return element-(ptrdiff_t)array;
}

void execute_array_index()
{
    printf("***********************************************'\n");
    printf("Execute the issue of array index  --- Start!\n");
    size_t i=0x7FFFFFFF;
    int j=0x7FFFFFFF;
    size_t loop_counter=0;
    uint8_t * threeDarray;      
    while(loop_counter<2)
    {
	    printf("\nloop--------------------------------------------\n");
        printf("The element should be accessed is No. 0x%zx \n",i);
	    printf("The right element been accessed is No. 0x%tx \n",Get_element_correct(threeDarray,i));
        printf("The wrong element been accessed is No. 0x%tx \n",Get_element_wrong(threeDarray,j));
        i++;
        j++;
        loop_counter++;
    }
    
    printf("Execute the issue of array index --- End!\n");
    printf("***********************************************'\n\n");
}

