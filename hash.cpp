#include"bits/stdc++.h"
using namespace std;

int main()
{
    int i,n;
    cin>>n;
    int x[n];
    for(i = 0 ; i < n ; i++)
    {
        cin>>x[i];
    }
    
    static int hash[100];
    int id=0;
    for(i = 0 ; i < n ; i++)
    {
        hash[x[i]]++;
    }
    i=0;
    while(i < 10)
    {
        cout<<hash[i];
        i++;
    }
    
    
    return 0;
}










