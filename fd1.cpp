#include<bits/stdc++.h>
using namespace std;
//union,intersection, difference,symmetric diff. of set 

int unin(int x[],int a,int y[],int b);
int inter(int x[],int a,int y[],int b);
int diff(int x[],int a,int y[],int b);
int main()
{
    int i,j,k,m,n,a,b;
    printf("enter the size of set A");
    scanf("%d",&a);
    printf("enter the size of set B");
    scanf("%d",&b);
    int x[a],y[b];

    printf("enter elements in set A");
    for(i = 0 ; i < a ; i++)
    {
        scanf("%d",&x[i]);
    }
    printf("enter elements in set B");
    for(i = 0 ; i < b ; i++)
    {
        scanf("%d",&y[i]);
    }
    //menu driven program
    int ch;
    do
    {
    printf("PRESS 1:UNION\nPRESS 2:INTERSECTION\nPRESS 3:DIFFERENCE");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: unin(x,a,y,b);break;
        case 2: inter(x,a,y,b);break;
        case 3: diff(x,a,y,b);break;
    }
    
    }while(ch!=3);
    return 0;
}

int unin(int x[],int a,int y[],int b)
{
    int c=a+b,i,j,d=0,temp = 0;
	int z[c];
	
	for(i = 0 ; i < a ; i++)
	{
		z[i] = x[i];
	}
	for(i = 0 ; i < b ; i++)
	{
		z[a+i] = y[i];
	}
	
	//sorting z[c] in ascending order
	for(i = 0 ; i < c ; i++)
	{
		for(j = i+1 ; j < c ;j++)
		{
			if(z[i] > z[j])
			{
				temp = z[i];
				z[i] = z[j];
				z[j] = temp;
			}
		}
	}
	
	for(i = 0 ; i < c ; i++)
	{
		for(j = i+1 ; j < c ; j++)
		if(z[j]==z[i])
		z[j]=NULL;
		
	}
		
	for(i = 0 ; i < c ; i++)
	if(z[i]!=NULL)
	printf(" %d",z[i]);
	 
	return 0;
}

int inter(int x[],int a,int y[],int b)
{
    int c,i,j,d=0,temp = 0;
	int z[c];
	
	for(i = 0 ; i < a ; i++)
	{
	    for(j = 0 ; j < b ; j++)
	    {
	        if(x[i] == y[j])
	        {
	            printf("%d ",x[i]);
	        }
	        else
	        continue;
	    }
	}
	printf("\n");
    return 0;
}

int diff(int x[],int a,int y[],int b)
{
    int i,j,k;
    for(i = 0 ; i < a ; i++)
    {
        for(j = 0 ; j < b ; j++)
        {
            if(x[i] != y[j])
            {
                printf("%d ",x[i]);
                break;
            }
            else
            break;
        }
    }
    return 0;
}
