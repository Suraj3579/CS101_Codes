#include<stdio.h>
char brct[256];
int top=-1;
void push(char c)
    {
    brct[++top]=c;
    }
char pop()
    {
    if(top==-1)
        {
        
        }
    else
        {
        return(brct[top--]);
        }
    }    
int isempty()
    {
    if(top==-1)return 1;
    else return 0;    
    }
int main()
    {
    char c;
    printf("enter\n");
    while(1)
        {
            scanf("%c",&c);
            if(c=='\n')
            {
                 
               break;
            }     
            else if(c=='[')
            {
                push(c);
            }
            else if(c==']'&& isempty()==0)
            {
                pop();
            }    
            else if(c==']'&& isempty()==1)
            {
                printf("unbalanced\n");
                return 0;
            }
        } 
    if(isempty()==1)printf("balanced\n");
    else printf("unbalanced\n");
    }       
                  
