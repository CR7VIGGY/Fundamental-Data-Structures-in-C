#include<stdio.h>

typedef struct file
{
    int roll;
}file;
FILE *ptr,*pt;

void insert()
{
    file f;
    fseek(ptr,0,2);
    printf("enter roll");
    scanf("%d",&f.roll);
    fprintf(ptr,"%d",f.roll);
}

void display()
{
    file f;
    rewind(ptr);
    while(!feof(ptr))
    {
        fscanf(ptr,"%d",&f.roll);
        printf("%d",f.roll);
    }
}
void search()
{
    file f;
    int roll;
    scanf("%d",&roll);
    fopen("atul.txt","r+");
    rewind(ptr);
    while(!feof(ptr))
    {
    fscanf(ptr,"%d",&f.roll);
        if(roll == f.roll)
        {
            printf("yess");
        }
    }
    
}
void modify()
{
    file f;
    int roll;
    scanf("%d",&roll);
    fopen("atul.txt","r+");
    rewind(ptr);
    while(!feof(ptr))
    {
    fscanf(ptr,"%d",&f.roll);
        if(roll == f.roll)
        {
            printf("enter new roll");
            scanf("%d",&f.roll);
            
            fprintf(ptr,"%d",f.roll);
        }
    }
}
int main()
{
    ptr = fopen("atul.txt","r+");
    if(ptr == NULL)
    {
        fopen("atul.txt","w+");
    }    
    insert();
    display();
    search();
    modify();
    display();
}
