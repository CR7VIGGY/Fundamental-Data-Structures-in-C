#include<bits/stdc++.h>
using namespace std;

struct info
{
    int age;
    char name[20];
    float wt;
};
struct info s;
struct info *ptr;



int main()
{
ptr = &s;
    printf("enter name");
    scanf("%s",&s.name);
    printf("enter age");
    scanf("%d",&s.age);
    printf("enter ur weight");
    scanf("%f",&s.wt);
    
    printf("%s %d %f",s.name,s.age,s.wt);
    printf("%s %d %f",ptr->name,ptr->age,ptr->wt);
    
    return 0;
}
