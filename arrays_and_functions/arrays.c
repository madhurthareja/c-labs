//Learning about arrays

#include <stdio.h>

//Function definition
float findAverage(int arr[], int size);

//Function to find the average of the marks
float findAverage(int arr [], int size){
	int i;
	float sum=0;
	for(int i=0; i<size; i++){
		sum+=arr[i];
	}
	return sum/size;
}

//Main function
int main(){
	int marks[5]={10,20,30,40,50};
	float average;
	average = findAverage(marks, 5);
	printf("The average of the marks is: %f\n", average);
	return 0;
}
