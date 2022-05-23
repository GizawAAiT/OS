#include <stdio.h>
#include <stdlib.h>
typedef struct node 
{
    int val ;
    struct node* next;
}node;
  

void main(){
    int a[]={1,2,3,4,5,6,7,8,9,1,22,3,
    44,55,66,77,88,99,43,53,64,75,85};
   int  siz=sizeof(a)/sizeof(a[0]);
    node* head = malloc(sizeof(node));

    head -> val =a[0];
    head -> next= NULL;
    

    node* temp = malloc(sizeof(node));

    temp->next=head;
    head=temp;
    for (
        int i = 1; i <siz ; i++)
    {
        node* cur = malloc(sizeof(node));
        cur->next=NULL;
        cur->val= i*111;
        temp->next=cur;
        temp=temp->next;
     
    }
    
    for (int i = 0; i < siz-1; i++)
    {
       printf("%d,%s",head->next->val,"\n");
       head=head->next;
    }
    
  
    

    // printf("%d,%d,%d,%d",head->val,cur->val,cur2->val,cur3->val);
    
}
