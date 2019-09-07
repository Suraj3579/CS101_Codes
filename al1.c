#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct matrix
{
	int row;
	int column;
	float value;
	struct matrix* next;
};

struct matrix* createnode()
{
	struct matrix* temp;
	temp=(struct matrix *)malloc(sizeof(struct matrix));
	return temp;
}

struct matrix* read_matrix(int n)
{
	struct matrix* head=NULL;
	int r,c; float x;
	scanf("%d %d %f\n",&r,&c,&x);
	struct matrix* temp;
	temp=createnode();
	temp->row=r;
	temp->column=c;
	temp->value=x;
	head=temp;

	for (int i = 0; i < n-1; i++)
	{
		scanf("%d %d %f\n",&r,&c,&x);
		struct matrix* temp1=createnode();
		temp1->row=r;
		temp1->column=c;
		temp1->value=x;
		temp->next=temp1;
		temp=temp1;
		//printf("%f\n", temp->value);
	}
	temp->next=NULL;


	return head;
}

float get_element(struct matrix* head, int r, int c)
{
	struct matrix* temp=head;
	while(temp!=NULL)
	{
		if(temp->row==r && temp->column==c)
		{
			return temp->value;
		}
	temp=temp->next;
	}

}

void print(struct matrix* head)
{

	int n=0;
	struct matrix* temp=head;
	while(temp!=NULL)
	{
		n++;
		temp=temp->next;
	}
	temp=head;
	for (int i = 0; i < (int)sqrt(n); i++)
	{
		for (int j = 0; j < (int)sqrt(n) ; j++)
		{
			printf(" %f ",temp->value);
			temp=temp->next;
		}
	printf("\n");
	}
}

void multiply_linked_lists(struct matrix* a,struct matrix* b, int k)
{
	int n=(int)sqrt(k);
	float res[n][n];
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int s=0;
			for (int k = 0; k <=n; ++k)
			{
				res[i][j]+=get_element(a,i,k)*get_element(b,k,j);
			}
			printf(" %f ",res[i][j] );
		}
		printf("\n");
	}
}


int main(void)
{
	int n; //n is the number of elements in a matrix
	scanf("%d\n",&n);
	struct matrix* a=read_matrix(n);
	struct matrix* b=read_matrix(n);
	multiply_linked_lists(a,b,n);

}
