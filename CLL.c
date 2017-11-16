#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coe,exp;
    struct node *next;
};
//

struct node  *create(int n)
{
    struct node *head=NULL;
    
    struct node *p;
    p = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    p = temp;
    head = temp;
    while(n>0)
    {
        scanf("%d",&p->coe);
        scanf("%d",&p->exp);
        struct node *t = (struct node *)malloc(sizeof(struct node));
        p->next = t;
        p=t;
        n--;
    }
    
    p->next = head;
    return head;
}

void display(struct node *head)
{
    struct node *p;
    p = head;
    while(p->next!=head)
    {
        printf("%dx^%d  ",p->coe,p->exp);
        p=p->next;
    }
}

void add(struct node *h1,struct node *h2)
{
    struct node *p1,*p2;
    p1 = h1;
    p2 = h2;
    while(h1->next!=p1&&h2->next!=p2)
    {
        if(h1->exp==h2->exp)
        {
            printf("%dx^%d",h1->coe+h2->coe,h1->exp);
            h1 = h1->next;
            h2 = h2->next;
            
        }
        else if(h1->exp>h2->exp)
        {
            printf("%dx^%d",h1->coe,h1->exp);
            h1 = h1->next;
        }
        else if(h2->exp > h1->exp)
        {
            printf("%dx^%d",h2->coe,h2->exp);
            h2 = h2->next;
        }
    }
}
int main()
{
    struct node *h1,*h2,*h3;
    h1 = create(3);
    display(h1);
    h2 = create(3);
    display(h2);
    add(h1,h2);
    
    
    return 0;
}








