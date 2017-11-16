#include<stdio.h>

struct file
{
    int roll;
};
file *ptr,*pt;

void insert()
{
    file f;
    fseek(ptr,0,2);
    printf("enter roll");
    scanf("%d",&f.roll);
    fprintf("%d",f.roll
}

void display()
{
    file f;
    f.rewind(ptr);
    while(!feof(ptr))
    {
        fscanf("%d",&f.roll);
        printf("%d",f.roll);
    }
}
int main()
{
    ptr = fopen("atul.txt",r+);
    if(ptr == NULL)
    {
        fopen("atul.txt",w+);
    }    
    insert();
    display();
}
