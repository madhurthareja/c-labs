//Understanding loops

#include <stdio.h>
int main(){
	printf("Printing first 10 even numbers with a for loop\n");
	for(int i=0;i<20;i+=2){
		printf("%d\n",i);
	}
	printf("Printing first 10 even numbers with a while loop\n");
	int i=0;
	while(i<20){
		printf("%d\n",i);
		i+=2;
	}
}
