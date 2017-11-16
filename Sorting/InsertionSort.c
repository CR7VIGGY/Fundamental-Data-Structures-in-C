#include<stdio.h>

int insertionsort(int x[],int n)
{
    int i,j,k;
    int key;
    
    for(i = 1 ; i < n ; i++)
    {
        key = x[i];
        j = i-1;
        while(j>=0 && key < x[j])
        {
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = key;
    }
    
    for(i = 0 ; i < n ; i++)
    {
        printf("%d ",x[i]);
    }
}

int main()
{
    int i,n;
    scanf("%d",&n);
    
    int x[n];
    
    for(i = 0 ; i < n ; i++)
    {
        scanf("%d",&x[i]);
    }
    
    insertionsort(x,n);
    
    return 0;    
}
