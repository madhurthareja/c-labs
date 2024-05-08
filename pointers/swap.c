//Implementing call by value and call by reference
//Author: Madhur Thareja

#include <stdio.h>

//function to swap two numbers using call by value
void swapByValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    printf("After swapping in swapByValue function: a = %d, b = %d\n", a, b);
}

//function to swap two numbers using call by reference

void swapByReference(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("After swapping in swapByReference function: a = %d, b = %d\n", *a, *b);
}

//main function

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Before swapping: a = %d, b = %d\n", a, b);
    swapByValue(a, b);
    printf("After swapping in main function: a = %d, b = %d\n", a, b);
    swapByReference(&a, &b);
    printf("After swapping in main function: a = %d, b = %d\n", a, b);
    return 0;
}

//The noticeable difference is:
//In call by value, the actual parameters are not changed, only the formal parameters are changed.
//In call by reference, the actual parameters are changed.
