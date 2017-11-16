#include<stdio.h>

void swap(int *x,int *y)
{
    int t;
    t  = *x;
    *x = *y;
    *y = t;
}
int bnrule(int x[],int low,int high)
{
    int j,k;
    int pvt = x[high];
    int i = low-1;
    
    for(j = low ; j <= high-1 ; j++)
    {
        if(x[j] <= pvt)
        {
            i++;
            swap(&x[i],&x[j]);
        }
    }
    swap(&x[i+1],&x[high]);
    return (i+1);
}

void Sort(int x[],int low,int high)
{
    if(low < high)
    {
        int p = bnrule(x,low,high);
        Sort(x,low,p-1);
        Sort(x,p+1,high);
    }
}

int main()
{
	int a,m;
		
	do
	{
		printf("PRESS 1:QUICK SORT\nPRESS 2:MERGE SORT");
		scanf("%d",&m);
		printf("Enter the Size of Array");
		scanf("%d",&a);
	    int x[a],arr[a];
		switch(m)
		{
			case 1 : printf("Enter the elements in Array");
				     for(int i = 0 ; i < a ; i++)
				     scanf("%d",&x[i]);
				    
				     Sort(x, 0, a-1);
				    
				     printf("SORTED ARRAY IS:");
				   
				    	for (int i=0; i < a; i++)
				        printf("%d ", x[i]);
				    	printf("\n");break;
				    	
			case 2 :    printf("Enter the elements in Array");
					     for(int i = 0 ; i < a ; i++)
					     scanf("%d",&arr[i]);
						 mergeSort(arr, 0, a - 1);
 						 printf("\nSorted array is \n");
						 printArray(arr, a);break;
						    
		}
	}
	while(m!=2);
	
    	return 0;
}
