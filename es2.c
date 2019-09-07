#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct matrix
{
    int row;
    int col;
    float value;
    struct matrix *next;
};
struct matrix * createNode()
{
    struct matrix *temp;
    temp=(struct matrix *)malloc(sizeof(struct matrix));
    return temp;
}
struct matrix * read_matrix(int n)
{
    int r,c;
    float val;
    struct matrix *head=NULL;
    struct matrix *cur;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %f",&r,&c,&val);
        struct matrix *temp;
        temp=createNode();
        temp->row=r;
        temp->col=c;
        temp->value=val;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            cur=temp;    
        }
        else
        {
            cur->next=temp;
            cur=temp;
        }
    }
    return (head);
}
float get_element(struct matrix *head,int r,int c)
{
    struct matrix *cur=head;
    int n=0;
    while(cur!=NULL)
    {
        n++;
        cur=cur->next;
    }
    cur=head;
    for(int i=0;i<n;i++)
    {
        if(cur->row==r && cur->col==c) return (cur->value);
        cur=cur->next;    
    }
}
float norm(struct matrix *,int c)
{
    struct matrix* temp=head;
    int n=0;
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    int m=0
    for(int i=0;i<n;i++)
    {
        m=m+(get_element(head,i,c))*(get_element(head,i,c));
    }
}
void print(struct matrix *head)
{
    struct matrix* temp=head;
    int n=0;
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    for(int i=0;i<(int)sqrt(n);i++)
    {
        for(int j=0;j<(int)sqrt(n);j++)
            {
                printf(" %f ", get_element(head,i+1,j+1));
            }
            
        printf("\n");
    }
    
