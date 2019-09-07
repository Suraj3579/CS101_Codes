#include<stdio.h>
#include<stdlib.h>
struct node 
{
int value;
struct node *next;
};
struct node *head=NULL;
void push(int x)
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->value=x;
temp->next=head;
head=temp;
}
int pop(void)
{
int a;
a=head->value;
head=head->next;
return a;
}
int isempty()
{
if(head==NULL)return 1;
else return 0;
}
int stacktop()
{
return (head->value);
}
void main()
{
push(2);
push(3);
push(4);
int a=pop();
printf("%d\n",a);
int c=isempty(); 
printf("%d\n",c);
int b=stacktop();
printf("%d\n",b);
}
