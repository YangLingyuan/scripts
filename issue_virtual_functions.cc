#include<stddef.h>
#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>
#include<limits.h>
using namespace std;
/*
This issue occurs when the arguments of functions in derived class
and basement class are of different types, they might coincident in 32-bit system
but in 64-bit system derived functions should use the same type.    


*/

class Base
{
    public:
    virtual void print(size_t val)
        {
            printf("Value from Base class :0x%" PRIx64 " \n",val);
        }
};

class DerivedWrong:public Base
{
    public:
    void print(uint32_t val)
    {
        printf("Implementation only work in 32-bit system,corresponding argument type is uint32_t.\n");
        printf("Got value :0x%" PRIx64 "\n",val);
    }
};

class DerivedCorrect:public Base
{
    public:
    void print(size_t val)
    {
        printf("Implementation  work in both 32 and 64 bits system,corresponding argument type is memsize.\n");
        printf("Got value :0x%" PRIx64 "\n",val);
    }
};

void execute_virtual_functions()
{
    Base BaseObject;
    DerivedWrong DerivedWrongObject;
    DerivedCorrect DerivedCorrectObject;
    size_t value=ULONG_MAX;
    printf("*************************************************'\n");
	printf("Execute the issue of overloaded functions --- Start!\n\n");
    printf("The argument been transfered is 0xffffffffffffffff\n");
    printf("Argument type is memsize in base class\n");
    DerivedWrongObject.print(value);
    DerivedCorrectObject.print(value);
    printf("\nExecute the issue of overloaded functions --- End!\n");
	printf("***********************************************'\n\n");

}