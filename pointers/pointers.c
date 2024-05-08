//Understanding pointers
//Author: Madhur Thareja

#include <stdio.h>

struct student{
	int reg_no;
	char * name;
	int age;
	float CGPA;
};
typedef struct student *Student;

//Defining main function
int main(){
	struct student s1,s2,s3;
	Student P1,P2,P3;
	P1 = &s1; 
	P2 = &s2; 
	P3 = &s3;

	//Assigning values to the structure variables
	s1.reg_no = 101;
	s1.name = "Student A";
	s1.age = 20;
	s1.CGPA = 8.5;

	(*P2).reg_no = 102;
	(*P2).name = "Student B";
	(*P2).age = 21;
	(*P2).CGPA = 8.0;

	P3->reg_no = 103;
	P3->name = "Student C";
	P3->age = 22;
	P3->CGPA = 7.5;

	//All of the assignments are equivalent
	printf("Student 1: %d %s %d %f\n",s1.reg_no,s1.name,s1.age,s1.CGPA);
	printf("Student 2: %d %s %d %f\n",(*P2).reg_no,(*P2).name,(*P2).age,(*P2).CGPA);
	printf("Student 3: %d %s %d %f\n",P3->reg_no,P3->name,P3->age,P3->CGPA);
}


