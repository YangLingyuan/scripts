#include<stdio.h>
#include<stdint.h>
#include<limits.h>
/*Magic numbers are hard-coded value work for a specific code snippet on certian platform,
which might change at later stage, but hard to detect and update*/
#define Mask_ULONG_High_Bit_1 (~LONG_MAX)
#define Mask_ULONG_High_Bit_0 LONG_MAX



void execute_magic_numbers()
{
  size_t val0=0;
  size_t val1=ULONG_MAX;
  printf("**************************************************\n");
  printf("Execute the issue of magic numbers --- Start!\n\n");

  printf("Section 1: set the high bit of a variable, the variable is originally 0\n");
  printf("Correct implementation in both 32 and 64 bits system\n");
  val0=val0|Mask_ULONG_High_Bit_1;
  printf("The variable has been set to:0x%zx\n",val0);
  printf("Implementation only work in 32-bit system\n");
  val0=0;
  val0=val0|0x80000000;
  printf("The variable has been set to:0x%zx\n",val0);

  printf("-----------------------------------------------------\n");

  printf("Section 2: unset the high bit of a variable, the variable is originally ULONG_MAX\n");
  printf("Correct implementation in both 32 and 64 bits system\n");
  val1=val1 & Mask_ULONG_High_Bit_0;
  printf("The variable has been set to:0x%zx\n",val1);
  printf("Implementation only work in 32-bit system\n");
  val1=ULONG_MAX;
  val1=val1 & 0x7fffffff;
  printf("The variable has been set to:0x%zx\n",val1);

  printf("-----------------------------------------------------\n");

  printf("Section 3: represent the maximum value with -1\n");
  if((size_t)(-1)==0xffffffff) printf("On 32-bit system, maximum value of size_t is 0x%zx, equal to 0xffffffff",(size_t)(-1));
  else printf("On 64-bit system, maximum value of size_t is 0x%zx, not equal to 0xffffffff",(size_t)(-1));
  printf("\nExecute the issue of magic numbers --- End!\n");
  printf("**************************************************\n");
}
