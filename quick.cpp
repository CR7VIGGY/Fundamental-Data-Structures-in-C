#include<stdio.h>
#include<stdlib.h>
//Assgn 7 : Implement Quick sort/Merge Sort to sort the no.s w/w/o recursion

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
    printf("%d %d\t",*a ,*b);
    printf("\n");
}
 
int breaknrule (int x[], int low, int high)
{
    int pvt = x[high]; 
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
      
        if (x[j] <= pvt)
        {
            i++;    
            swap(&x[i], &x[j]);
        }
    }
    swap(&x[i + 1], &x[high]);
    return (i + 1);
}
 

void Sort(int x[], int low, int high)
{
    if (high > low)
    {
        int p = breaknrule(x, low, high);
 		//recursion
        Sort(x, low, p - 1);
        Sort(x, p + 1, high);
    }
}

int main()
{
	int a,m;
		
	do
	{
		printf("PRESS 1:QUICK SORT\n");
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
						    
		}
	}
	while(m!=2);
	
    	return 0;
}
