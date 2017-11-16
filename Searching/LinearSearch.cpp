#include<stdio.h>

int linearsearch(int x[],int n,int a)
{
	int i;
	
	for(i = 0 ; i < n ; i++)
	{
		if(x[i]==a)
		{
			printf("found");
			return 0;
		}
		
	}
	printf("not found");
	return 0;
}
int main()
{
	int n,a,i,c;
	scanf("%d",&n);
	
	int x[n];
	
	for(i = 0 ; i < n ; i++)
	{
		scanf("%d",&x[i]);
	}
	
	printf("enter a no. to search");
	scanf("%d",&a);
	
	linearsearch(x,n,a);
	
	
	
	return 0;
}
