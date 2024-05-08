//Understanding memory leaks
//Author: Madhur Thareja

#include <stdio.h>
#include <stdlib.h>

int main(){
	int *ptr = (int *)malloc(sizeof(int)*100);

	for (int i = 0; i < 100; i++){
		ptr[i] = i * i;
	}
	
	int *ptr2 = (int *)malloc(sizeof(int)*5);
	for (int i = 0; i < 5; i++){
		ptr2[i] = i * i * i;
	}
	ptr = ptr2; //Memory leak, ptr is pointing to a new memory location and the old memory location is not freed
		    //ptr and ptr2 are pointing to the same memory location, so the memory location pointed by ptr is lost
}
