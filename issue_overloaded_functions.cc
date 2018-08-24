#include<stddef.h>
#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>
using namespace std;

/*
Access overloaded functions with argument of memsize type will
be compiled  into different calls on different systems.In this 
example, a stack implemented with overloaded function can push 
and pop variable of uint32_t and uint64_t. When called with size_t
argument, the memory access pattern will vary in 64 or 32 bits systems. 
*/
struct stack
{
    size_t stack_space[10];
    void* top;
}StackObject;

static void* MAX_STACK=(void*)(&(StackObject.stack_space[9]));
static void* MIN_STACK=(void*)(&(StackObject.stack_space[0]));
static intptr_t CAPACITY_STACK=(intptr_t)MAX_STACK-(intptr_t)MIN_STACK;
//stack resides between StackObject[0] to StackObject[9]


class stackoperation{
    public:
    //Push an unsigned int variable of 4 bytes
    size_t Push(const uint32_t val)
    {
        uint32_t* temp_ptr=(uint32_t*)StackObject.top;
        if(((intptr_t)StackObject.top-(intptr_t)MIN_STACK)<=CAPACITY_STACK)
        {
            *temp_ptr=val;
            temp_ptr++;
            StackObject.top=(void*)temp_ptr;
            return 1;
        }
        return 0;
    }
    
    //Push an unsigned int variable of 8 bytes
    size_t Push(const uint64_t val)
    {
        uint64_t* temp_ptr=(uint64_t*)StackObject.top;
        if(((intptr_t)StackObject.top-(intptr_t)MIN_STACK)<=CAPACITY_STACK)
        {
            *temp_ptr=val;
            temp_ptr++;
            StackObject.top=(void*)temp_ptr;
            return 1;
        }
        return 0;
    }

    //Pop an unsigned int variable of 4 bytes
    size_t Pop(uint32_t & target)
    {
        uint32_t* temp_ptr=(uint32_t*)StackObject.top;
        if(((intptr_t)StackObject.top-(intptr_t)MIN_STACK)>0)
        {
            temp_ptr--;
            target=*temp_ptr;
            StackObject.top=(void*)temp_ptr;
            return 1;
        }
        return 0;
    }

    //Pop an unsigned int variable of 8 bytes
    size_t Pop(uint64_t & target)
    {
        uint64_t* temp_ptr=(uint64_t*)StackObject.top;
        if(((intptr_t)StackObject.top-(intptr_t)MIN_STACK)>0)
        {
            temp_ptr--;
            target=*temp_ptr;
            StackObject.top=(void*)temp_ptr;
            return 1;
        }
        return 0;
    }
    
};

void execute_overloaded_functions()
{
    stackoperation STACKOPERATION;
    size_t value_memsize[5]={1,2,3,4,5};
    uint32_t value_uint[5]={6,7,8,9,10};
    StackObject.top=MIN_STACK;
	printf("*************************************************'\n");
	printf("Execute the issue of overloaded functions --- Start!\n\n");
    printf("Implementation only correct in 32-bit system:\n");
    for(int i=0;i<5;i++)
    {
        if(STACKOPERATION.Push(value_memsize[i]) && STACKOPERATION.Pop(value_uint[i]))
        {
            printf("after 1 push and 1 pop:\n");
            printf("Current stack top point to byte No.%" PRIdPTR "\n", (intptr_t)StackObject.top-(intptr_t)MIN_STACK);
        }
            
        else printf("Error !\n");
    }
    printf("In 64-bit system, the stack operation takes more memory than it retrieves later\n");
    printf("-------------------------------------------------------------\n");
    StackObject.top=MIN_STACK;
    printf("\nImplementation correct in both 32 and 64 bits system:\n");

    for(int i=0;i<5;i++)
    {
        if(STACKOPERATION.Push(value_uint[i]) && STACKOPERATION.Pop(value_uint[i]))
        {
            printf("after 1 push and 1 pop:\n");
            printf("Current stack top point to byte No.%" PRIdPTR "\n", (intptr_t)StackObject.top-(intptr_t)MIN_STACK);
        }
            
        else printf("Error !\n");
    }
	printf("\nExecute the issue of overloaded functions --- End!\n");
	printf("***********************************************'\n\n");

}