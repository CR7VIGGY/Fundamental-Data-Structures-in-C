#include<stdio.h>
//iteravtive
int binarysearch(int x[],int n,int a)
{
    int low,high,mid;
    low = 0;
    high = n-1;
    mid = (low+high)/2;
    int flag = 0;
    
    while(low <= high)
    {
        if(x[mid] > a)
        {
            low = 0;
            high = mid-1;
            mid = (low+high)/2;  
        }
        else if(x[mid] < a)
        {
            low = mid +1;
            high = high;
            mid = (low+high)/2;
        }
        else if(x[mid] == a)
        {
            printf("element found");
            flag =1;
            return 0;
        }
       
    }
    printf("element not found");
    return 0;
}

int main()
{
    int n,i,j,temp = 0,a;
    printf("enter array size");
    scanf("%d",&n);
    
    int x[n];
    
    for(i = 0 ; i < n ; i++)
    {
        scanf("%d",&x[i]);
    }
    
    for(i = 0 ; i < n-1 ; i++)
    {
        for(j = i+1 ; j < n-i-1 ; j++)
        {
           if(x[i] > x[j])
           {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
           }
        }
    }
    
    printf("enter an element to search");
    scanf("%d",&a);
    
    binarysearch(x,n,a);
    
    return 0;
}
