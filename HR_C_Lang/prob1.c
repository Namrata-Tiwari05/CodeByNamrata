//  "Hello World!" in C 
#include<stdio.h>
#include<string.h>
#include <math.h>
#include<stdlib.h>

int main() 
{
	char s[100];
    scanf("%[^\n]%*c",&s);
     printf("Hello, World!\n"); 
     printf(s);
    return 0;
}
// This program reads a string from the user and prints "Hello, World!" followed by the input string.