#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

void insert(int data,int pos)
{
    int i;
    struct node *p,*t;
    p = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    
    if(pos == 1)
    {
        p = temp;
        p->next=head;
        head = temp;
        temp->data = data;
        return ;
    }
    
    
    for(i = 0 ; i < pos-2 ; i++)
    {
        
        p=p->next;
       
    }
     t = p->next;
     p->next = temp;
     temp->data = data;
     temp->next=t;
}

void display()
{
    int i;
    struct node *p;
    p = head;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p = p->next;        
    }
}

void delete(int pos)
{
    int i;
    struct node *p,*t,*tt;
    p = head;
    if(pos == 1)
    {
        head = p->next;
    }
    
    for(i = 0 ; i < pos-2 ; i++)
    {
        p = p->next;
    }
    t = p;
    p = p->next;
    tt = p;
    t->next=tt;
}

int main()
{
    int ch;
    insert(3,1);
    insert(4,1);
    insert(5,1);
    insert(6,3);
    display();
    delete(1);
    printf("\n");
    display();
    return 0;
}





