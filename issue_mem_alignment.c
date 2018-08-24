#include<stddef.h>
#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>

/*struct type with fixed length*/
struct AlignmentSample1
{
	uint32_t a;
	size_t * m_arr;
} * object1, *object2;



/*the right way to calculate the size of a struct 
  	*macro offsetof will cause synax warning under lint 
	*while there is actually no problem.
	
size_t mem_alignment_correct()
{
	size_t size=offsetof(struct AlignmentSample1,m_arr)+sizeof(size_t *);
	printf("Correct 64-bit implementation, aligned capacity =%zu \n",size);
	return size;
}
*/

/*correct in 32 bit machine while not OK in 64 bit machine	
size_t mem_alignment_wrong()
{
	size_t size=sizeof(uint32_t)+sizeof(size_t *);
	printf("Wrong 64-bit implementation, aligned capacity =%zu \n",size);
	return size;
}
*/



void execute_mem_alignment()
{
	size_t mem_size=0;
	printf("*************************************************'\n");
	printf("Execute the issue of memory alignment --- Start!\n\n");
	printf("The struct contains one uint32_t and one size_t pointer\n");
	mem_size=offsetof(struct AlignmentSample1,m_arr)+sizeof(size_t *);
	printf("Correct 64-bit implementation, aligned capacity =%zu \n",mem_size);
	object1=(struct AlignmentSample1*)malloc(offsetof(struct AlignmentSample1,m_arr)+sizeof(size_t *));

	mem_size=sizeof(uint32_t)+sizeof(size_t *);
	printf("Wrong 64-bit implementation, aligned capacity =%zu \n",mem_size);
	object2=(struct AlignmentSample1*)malloc(sizeof(uint32_t)+sizeof(size_t *));

	printf("Execute the issue of memory alignment --- End!\n");
	printf("***********************************************'\n\n");

}

