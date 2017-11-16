#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
};

struct node *head=NULL;

void insert(int data)
{
    struct node *p;
    
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    
    if(head == NULL)
    {
        temp->prev = NULL;
        temp->data = data;
        temp->next = NULL;
        head = temp;
        return ;
    }
    p = head;
    temp->prev = NULL;
    temp->data = data;
    temp->next = p;
    p->prev = temp;
    head = temp;
}

void display()
{
    struct node *p;
    p = head;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p = p->next;
    }    
}

void reverse()
{
    struct node *p;
    p = head;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    
    while(p!=NULL)
    {
        printf("%d",p->data);
        p = p->prev;
    }
}
int main()
{
    insert(2);
    insert(4);
    insert(3);
    insert(5);
    display();
    reverse();
    return 0;
}






