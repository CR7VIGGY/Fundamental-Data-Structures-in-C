#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next; 
};
struct node *head=NULL;

void create(int data,int n)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = NULL;
    temp->next = NULL;
    int i;
    
    if(n == 1)
    {
        temp->data = data;
        temp->next = head;
        head = temp;
        return ;
    }
    struct node *p;
    p = head;
    
    for(i=0;i<n-2;i++)
    {
        p = p->next;
    }
    temp->data = data;
    temp->next = p->next;
    p->next = temp;
}

void display()
{
    struct node *p;
    p = head;
    
    while(p != NULL)
    {
        printf("%d",p->data);
        p = p->next;
    }   
}

void delete(n)
{
    struct node *p,*t;
    p = head;
    int i;
    for(i = 0 ; i < n-2 ;i++)
       p = p->next;
    
    t = p->next;
    p->next = t->next;
    free(t);
    
}

int main()
{
    create(4,1);
    create(5,2);
    create(2,3);
    create(3,4);
    display();
    delete(2);
    display();
    return 0;
}













