 #include<stdio.h>

int partition(int x[],int low ,int high)
{
    int piv = x[high];
    int i=low-1,j=low;
    int temp=0;
    
    for(j = low ; j < high ; j++)
    {
        if(piv >= x[j])
        {
            i++;
            temp = x[i];
            x[i] = x[j];
            x[j] = temp;
        }
        
    }
    temp = 0;
    temp = x[i+1];
    x[i+1] = x[high];
    x[high] = temp;
    
    return (i+1);

}

int quicksort(int x[],int low,int high)
{
    if(low < high)
    {
        int p = partition(x,low,high);
        quicksort(x,low,p-1);
        quicksort(x,p+1,high);
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
    
    quicksort(x,0,n-1);
    
    for(i = 0 ; i < n ; i++)
    {
        printf("%d ",x[i]);
    }
    return 0;
}
