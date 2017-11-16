#include<stdio.h>
#include<stlib.h>

void merge(int x[],int low,int m,int high)
{
    int i,j,k;
    int n1,n2;
    n1 = m - low +1;
    n2 = high - m;
    
    int L[n1],R[n2];
    
    for(i = 0 ; i < n1 ; i++)
    {
        L[i] = x[low+i];
    }
    for(j = 0 ; j < n2 ; j++)
    {
        R[j] = x[m+1+j];
    }
    
    i=0,j=0,m=low;
    
    while(i < n1 && j < n2)
    {
        if(L[i] < R[j])
        {
            x[k] = L[i];
            i++;
        }
        else
        {
            x[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i < n1)
    {
        x[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        x[k] = R[j];
        j++;
        k++;
    }
    
}

void mergesort(int x[],int low,int high)
{
    if(low < high)
    {
        int m;
        m = low+(high-low)/2;
        mergesort(x,low,m);
        mergesort(x,m+1,high);
        
        merge(x,low,m,high);
    }
    
}

int main()
{
    int i,j,n;
    scanf("%d",&n);
    
    int x[n];
    
    for(i = 0 ; i < n ; i++)
    {
        scanf("%d",&x[i]);
    }
    
    mergesort(x,0,n-1);
    
    for(j = 0 ; j < n ; j++)
    {
        printf("%d",x[j]);
    }
    return 0;
}
