#include<stdio.h>
#include<stdlib.h>  
 struct node
  {
  int d;
  struct node * n;
  }
  ;
  
  typedef struct node node; 
  
  node * create( )
  { node * p=(node *)malloc(sizeof(node));
    node * h=p;
    int n;
    printf("write the size\n");
      scanf("%d",&n);
      if(n==0)return 0;
    printf("write nos\n");
    int i;
	for( i=0;i<n;i++){
      scanf("%d",&p->d);
      if(i==n-1)break;
	  p->n=(node *)malloc(sizeof(node));
      p=p->n; 
    }
    p->n=0;
   
  return h;
  }

 
 void search(node * p)
  { 
    int n;
    printf("write no to search\n");
    scanf("%d",&n);
    printf("\n");
    int i=1;
    while(p!=0){
    if(p->d==n){printf("element found at %d position\n ",i);}
    p=p->n;
    i++; 
    }
   
  
  
  }
  
  void insert(node **h){
  	int n,p;
  	node *l=*h;
  	node * t=(node *)malloc(sizeof(node));
    printf("write no to insert\n");
    scanf("%d",&t->d);
    printf("write insertion point\n");
    scanf("%d",&p);
    int i=1;
    if(p==1){
 
    t->n=*h;
	*h=t;
	return ; 	
	}    
	while(i<p-1)
	{ 
		l=l->n;
	i++;
	}
		t->n=l->n;
	l->n=t;
  	
  	
  }

 void dis(node * p)
   {
    while(p!=0){
    printf("%d\t ",p->d);
    p=p->n;
   
    }
   printf("\n");
  
  
  }

 void rev(node ** z)
  {  node * prev=0;
     node * temp;
	 node *s=*z;
     while(s!=0)
	 { temp=s->n;  
	   s->n=prev;
	   prev=s;
	   s=temp; 
	 }
      *z=prev;
  }

 node * del(node * h)
  { 
    int n;
    printf("write no to delete\n");
    scanf("%d",&n);
    printf("\n");
    
    node *p=h;
    if(h->d==n){return h->n;}
    int i=1;
    while(p!=0){
    if(p->n->d==n){p->n=p->n->n;return h;}
    p=p->n;
    i++; 
    }
  
  
  }

 

 
void main()
   {
  int n,e=1;
  node * h;
  while(e)
  {
  
    printf("write 0 to exit\nwrite 1 to create\nwrite 2 to display\nwrite 3 to search\nwrite 4 for delete\nwrite 5 for revert\nwrite 6 to insert\n");
           scanf("%d",&e);
  
    switch(e) 
  {
    case 1 :h=create(); break;
    case 2 : dis(h); break;
   	case 3 : search(h); break;
    case 4 : h=del(h); break;
    case 5 : rev(&h); break;
    case 6 : insert(&h);break;
   }
} 
    
  
  
  
  
  }
  
  
  
   
