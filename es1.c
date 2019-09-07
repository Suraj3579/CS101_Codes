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
    for(int i=1;i<n+1;i++)
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
void multiply_linked_lists(struct matrix *a,struct matrix *b,int n)
{
    float ar[20][20];
    for(int i=1;i<=sqrt(n);i++)
    {
        for(int j=1;j<=sqrt(n);j++)
        {   
            float m=0;
            for(int k=1;k<=sqrt(n);k++)
            {
                m=m+((get_element(a,i,k))*(get_element(b,k,j)));
            } 
            ar[i-1][j-1]=m;
        }
    }
    for(int i=0;i<sqrt(n);i++)
    {
        for(int j=0;j<sqrt(n);j++)
        {
            printf("%f ",ar[i][j]);
        }
        printf("\n");
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
    
}
void main()
{
    int n;
    struct matrix *r,*c;
    scanf("%d",&n);
    r=read_matrix(n);
    c=read_matrix(n);
    multiply_linked_lists(r,c,n);
    printf("\n");
    print(r);
    printf("\n");
    print(c);
}

    
