//Understanding dynamic memory allocation in C
//Author: Madhur Thareja

#include <stdio.h>
#include <stdlib.h>

//Function to populate the dynamic array
void populateDynamicArray(int *arr, int size){
	int i;
	for(i=0; i<size; i++){
		printf("Enter the element %d: ", i+1);
		scanf("%d", &arr[i]);
	}
}

//Function to display the elements of the array
void displayDynamicArray(int *arr, int size){
	int i;
	printf("The elements of the array are: ");
	for(i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//Function to compute the average of the elements in the array
float computeAverage(int *arr, int size){
	int i;
	float sum=0;
	for(i=0; i<size; i++){
		sum += arr[i];
	}
	return sum/size;
}

//Defining main function

int main(){
	int size=3;
	int *arr;

	//Allocating memory for the array
	arr = (int *)malloc(size * sizeof(int));

	//populating the array
	populateDynamicArray(arr, size);

	//Displaying the array
	displayDynamicArray(arr, size);

	//Computing the average of the array
	float avg = computeAverage(arr, size);
	printf("The average of the array is: %f\n", avg);

	//memory leak and freeing the memory
}
