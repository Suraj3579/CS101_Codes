#include<stdio.h>
#include<stdlib.h>
struct matrix 
{
int a;
struct matrix *p;

};


void main()
{
printf("HI");
struct matrix b;
b.a=5;
printf("%d",b.a);
}

