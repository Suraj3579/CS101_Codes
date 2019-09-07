#include<stdio.h>
#include<stdlib.h>
struct node
{
int value;
struct node *next;
};
void print(struct node *str)
{
struct node *temp;
temp=str;
while (temp!=NULL)
{
printf(" %d ",temp->value);
temp=temp->next;
}
}
void start(struct node **str,int x)
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->value=x;
temp->next=NULL;
if(*str==NULL)
{
*str=temp;
}
else
{
temp->next=(*str);
(*str)=temp;
}
}
void end(struct node **str,int x)
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->value=x;
temp->next=NULL;
struct node *temp1;
temp1=(*str);
if(temp1==NULL)
{
start(&temp1,x);
}
while(temp1->next!=NULL)
{
temp1=temp1->next;
}
temp1->next=temp;
}
void afterN(struct node **str,int x,int y)
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->value=x;
temp->next=NULL;
struct node *temp1;
temp1=(*str);
while(temp1!=NULL)
{
if(temp1->value==y)
{
break;
}
else
{
temp1=temp1->next;
}
temp->next=temp1->next;
temp1->next=temp;
}
}
void afterP(struct node **str,int x,int y)
{
if(y==0)
{
start(str,x);
return;
}
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->value=x;
temp->next=NULL;
struct node *temp1;
temp1=(*str);
for(int i=0;i<y-1;i++)
{
temp1=temp1->next;
}
temp->next=temp1->next;
temp1->next=temp;
}
void deleteN(struct node **str,int x)
{
struct node *cur;
struct node *prev;
cur=(*str);
prev=NULL;
if((*str)->value==x)
{
(*str)=(*str)->next;
}
else
{
while(cur!=NULL)
{
if(cur->value==x)break;
else
{
prev=cur;
cur=cur->next;
}
}
prev->next=cur->next;
cur->next=NULL;
free(cur);
}
}
void deleteP(struct node **str,int pos)
{
struct node *cur;
struct node *prev;
cur=(*str);

if(pos==1)
{
*str=(*str)->next;
return;
}
else
{
for(int i=0;i<pos-1;i++)
{
prev=cur;
cur=cur->next;
}
prev->next=cur->next;
cur->next=NULL;
free(cur);
}
}
int search(struct node *str,int x)
{
struct node *temp1;
temp1=str;
while(temp1!=NULL)
{
if (temp1->value==x)
return 1;
else
temp1=temp1->next;
}
return 0;
}
int main(void)
{
struct node *head;
head=NULL;
printf("Enter\n");
while(1)
{
int a,b;
char c;
scanf("%d%c%d",&a,&c,&b);
if(a==0&&b==0&&c=='0')
{
break;
}
switch(c)
{
case's':start(&head,a);break;
case'e':end(&head,a);break;
case'a':afterP(&head,a,b);break;
case'D':deleteN(&head,a);break;
case'd':deleteP(&head,a);break;
case'A':afterN(&head,a,b);break;
case'p':print(head);break;
case'S':search(head,a);break;
default:printf("not valid\n");break;
}
}
}

