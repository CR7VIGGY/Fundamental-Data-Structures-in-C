//VIGHNESH TIWARI , 4252 , AIT PUNE , INDIA
//GITHUB PROFILE : CR7VIGGY
#include<stdio.h>


void add(int a,int b,int x[][10],int c,int d, int y[][10]);
void sub(int a,int b,int x[][10],int c,int d, int y[][10]);
void mul(int a,int b,int x[][10],int c,int d, int y[][10]);
void tran(int a,int b,int x[][10],int c,int d, int y[][10]);

int main()
{
	int a,b,c,d,i,j,m;
	printf("ENTER THE ROW AND COLOUMN SIZE OF MATRIX A");
	scanf("%d %d",&a,&b);

	int x[a][10];
	
	printf("enter 1st matrix\n");
	for(i = 0 ; i < a ; i++)
	{
		for(j = 0 ; j < b ; j++)
		{
			scanf("%d",&x[i][j]);
		}
	}
	printf("ENTER THE ROW SIZE OF MATRIX B");
	scanf("%d %d",&c,&d);
	
	int y[c][10];
	
	printf("enter 2nd matrix\n");
	for(i = 0 ; i < c ; i++)
	{
		for(j = 0 ; j < d ; j++)
		{
			scanf("%d",&y[i][j]);
		}
	}
	do
	{
	
		printf("PRESS 1 : ADD\nPRESS 2 : SUB\nPRESS 3 : MULTIPLY\nPRESS 4 : TRANSPOSE\nPRESS 5 : SADDLE POINT\nPRESS 6 : EXIT");
		scanf("%d",&m);
		
		switch(m)
		{
			case 1 : add(a,b,x,c,d,y);break;
			case 2 : sub(a,b,x,c,d,y);break;
			case 3 : mul(a,b,x,c,d,y);break;
			case 4 : tran(a,b,x,c,d,y);break;
			case 5 : ;break;
			case 6 : ;break;
		}
	}
	while(m!=6);
}

void add(int a,int b,int x[][10],int c,int d,int y[][10])
{
	int e,f,i,j;
	if(a == c&&b==d)
	{
		e = a;
		f = b;
	}
	else
	printf("!!!!!!!!!!!!!ERROR IN YOUR MATRIX SIZE!!!!!!!!!!!!!!!");
	int z[e][f];
	
	for(i = 0 ; i < e ; i++)
	{
		for(j = 0 ; j < f ; j++)
		{
			z[i][j] = x[i][j] + y[i][j];
		}
	}
	for(i = 0 ; i < e ; i++)
	{
		for(j = 0 ; j < f ; j++)
		{
			printf("%d",z[i][j]);
			printf(" ");
		}printf("\n");
	}
	
}

void sub(int a,int b,int(*x)[10],int c,int d, int(*y)[10])
{
	int e,f,i,j;
	if(a == c)
	{
		e = a;
		f = b;
		printf("\nSub is\n");
	
		for(i=0;i<e;i++)
		{
			for(j=0;j<f;j++)
			{
				printf("%d  ", *(*(x+i)+j) - *(*(y+i)+j)  );
			}
			printf("\n");
		}
	}
	else
	printf("!!!!!!!!!!!!!ERROR IN YOUR MATRIX SIZE!!!!!!!!!!!!!!!");
	
}

void mul(int a,int b,int x[][10],int c,int d, int y[][10])
{
	int e,f,i,j,k;
	e = a;
	f  = d;
	int z[e][f];
	if(c != b)
	printf(".........error........\n");
	else
	{
		for(i = 0 ; i < e ; i++)
		{
			for(j = 0 ; j < e ; j++)
			{
				z[i][j] = 0;
				for(k = 0 ; k < e ; k ++)
				{
					z[i][j] = z[i][j] + (x[i][k]*y[k][j]);
				}
			}
		}
		for(i = 0 ; i < e ; i++)
		{
			for(j = 0 ; j < f ; j++)
			{
				printf("%d",z[i][j]);
			}
			printf("\n");
		}
	}
	
	
}

void tran(int a,int b,int x[][10],int c,int d, int y[][10])
{
	int i,j,k;
	printf("transpose of matrix A\n");
	for(i = 0 ; i < a ; i++)
	{
		for(j = 0 ; j < b ; j++)
		{
			printf("%d",x[j][i]);
		}printf("\n");
	}
	
	printf("transpose of matrix B\n");
		for(i = 0 ; i < c ; i++)
	{
		for(j = 0 ; j < d ; j++)
		{
			printf("%d",y[j][i]);
		}printf("\n");
	}
}






