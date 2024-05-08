//Understanding structs in C
//Author: Madhur Thareja

#include <stdio.h>
#include <string.h>
 
struct student {
	int registrationNumber;
	char name[50];
	int age;
	float CGPA;
};

void updateCGPA (int length, struct student students[length], int registrationNumber, float newCGPA){
	for (int i=0;i<length;i++){
		if(students[i].registrationNumber == registrationNumber){
			students[i].CGPA = newCGPA;
			break;
		}
	}
	return;
}

//defining main function
int main(){
	//Create an array of studens of size 3
	struct student students[3];

	//Initialize the first student
	students[0].registrationNumber = 1;
	strcpy(students[0].name, "Student A");
	students[0].age = 20;
	students[0].CGPA = 8.0;

	//Initialize the second student
	students[1].registrationNumber = 2;
	strcpy(students[1].name, "Student B");
	students[1].age = 21;
	students[1].CGPA = 8.5;

	//Initialize the third student
	students[2].registrationNumber = 3;
	strcpy(students[2].name, "Student C");
	students[2].age = 22;
	students[2].CGPA = 9.0;

	//Update the CGPA of the student with registration number 2
	printf("Before updating CGPA of Student B %f \n ", students[1].CGPA);
	updateCGPA(3, students, 2, 9.5);
	printf("After updating CGPA of Student B %f \n", students[1].CGPA);
}
