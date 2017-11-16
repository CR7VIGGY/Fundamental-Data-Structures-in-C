#include"stdio.h"

int main()
{
    int a,b,c,d;
    int cnt1=0,cnt2=0;
    printf("enter matrix size of Matrix A:");
    scanf("%d %d",&a,&b);
    printf("enter matrix size of Matrix B:");
    scanf("%d %d",&c,&d);
    
    int x[a][b],y[c][d];
    
    for(int i = 0 ; i < a ; i++)
    for(int j = 0 ; j < b ; j++)
    scanf("%d",&x[i][j]);
    
    printf("enter elemets in Matrix B:\n");
    for(int i = 0 ; i < c ; i++)
    for(int j = 0 ; j < d ; j++)
    scanf("%d",&y[i][j]);
    
    //sparse banana
    
    printf("sparse matrix of A is :\n");
    printf("Row\tColumn\tNonzero\n");
    
    for(int i = 0 ; i < a ; i++)
    {
        for(int j = 0 ; j < b ; j++)
        {
            if(x[i][j] == 1)
            {
                printf("%d\t%d\t%d",i,j,x[i][j]);
                cnt1++;
            }
            printf("\n");
        }
        
    }
    
    printf("sparse matrix of B is :\n");
    printf("Row\tColumn\tNonzero\n");
    
    for(int i = 0 ; i < c ; i++)
    {
        for(int j = 0 ; j < d ; j++)
        {
            if(y[i][j] == 1)
            {
                printf("%d\t%d\t%d",i,j,x[i][j]);
                cnt2++;
            }
            printf("\n");
        }
        
    }
    
    printf("simple transpose of matrix A:\n");
    
    printf("Row\tColumn\tNonzero\n");
    
    for(int i = 0 ; i < a ; i++)
    {
        for(int j = 0 ; j < b ; j++)
        {
            if(x[i][j] == 1)
            {
                printf("%d\t%d\t%d",j,i,x[i][j]);
            }
            printf("\n");
        }
        
    }
    
    
    printf("\nRow\tColumn\tNonzero");
    
    for(int i = 0 ; i < c ; i++)
    {
        for(int j = 0 ; j < d ; j++)
        {
            if(y[i][j] == 1)
            {
                printf("%d\t%d\t%d",j,i,x[i][j]);
            }
            printf("\n");
        }
        
    }
    
    printf("\nfast transpose of matrix A:");
    int hash[b];
    int m[cnt1];
    int id=0;
    for(int i = 0 ; i < a ; i++)
    {
        for(int j = 0; j < b ; j++)
        if(x[i][j] == 1)
        {
            m[id] = j;
        }
    }
    
    
    for(int i = 0 ; i < cnt1 ; i++)
    hash[m[i]]++;
    
    for(int i = 0 ; i < b ; i++)
    printf("%d",hash[i]);
    
    
    return 0;
}











