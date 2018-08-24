#include<stdio.h>
struct Bitvariable
{
    unsigned int a:15;
    unsigned int b:13;
} object;

size_t bitField_correct(struct Bitvariable x, int num_of_bits)
{
	return ((size_t)x.a<<num_of_bits);	
}

size_t bitField_wrong(struct Bitvariable x, int num_of_bits)
{
	return (x.a<<num_of_bits);	
}


void execute_bit_field()
{
    printf("***********************************************'\n");
    printf("Execute the issue of bit field  --- Start!\n\n");
    object.a=0x4000;
    printf("Desired output is 0x80000000 \n");
    printf("Correct 64-bit implementation result: 0x%zx \n",bitField_correct(object,17));
    printf("Wrong 64-bit implementation result: 0x%zx \n\n",bitField_wrong(object,17));
    printf("Execute the issue of bit field --- End!\n");
    printf("***********************************************'\n\n");
}
