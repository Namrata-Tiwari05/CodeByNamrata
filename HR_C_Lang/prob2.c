// Playing With Characters 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char ch,s[100],sen[100];
    scanf("%c",&ch);
    scanf("%s",s);
    scanf("\n");
    scanf("%[^\n]s",sen);
    printf("%c\n%s\n%s",ch,s,sen);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
// This program reads a character, a string, and a sentence from the user and prints them in the specified format.