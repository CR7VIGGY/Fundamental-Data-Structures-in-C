#include<stdio.h>
#include<stdlib.h>  
 struct node
  {
  int rno;
  char name[30];
  int yr;
  struct node *n,*pv;
  }
  ;
  typedef struct node node; 
  node *h;
  node * create( )
  { node * p=(node *)malloc(sizeof(node));
    node * h=p;
    node * prev=0;
    int n;
    printf("write the size\n");
      scanf("%d",&n);
      if(n==0)return 0;
    int i;
	for( i=0;i<n;i++){
      printf("\nwrite rollno\twrite name\twrite year\n");
      scanf("%d%s%d",&p->rno,p->name,&p->yr);
      if(i==n-1)break;
	  p->n=(node *)malloc(sizeof(node));
      p->pv=prev;
      prev=p;
	  p=p->n; 
    }
    p->n=0;
    p->pv=prev;

  return h;
  }

   
  
  
  
  
  void insert(){
  	int n,p;
  	node *l=h;
  	node * t=(node *)malloc(sizeof(node));
    node * prev=0;
    printf("\nwrite rollno\twrite name\twrite year\n");
    scanf("%d%s%d",&t->rno,t->name,&t->yr);
    printf("write insertion point\n");
    scanf("%d",&p);
    int i=1;
    if(p==1){
    t->n=h;
    t->pv=0;
	h=t;
	return; 	
	}    
	while(i<p-1)
	{   
		l=l->n;
	i++;
	}
	t->n=l->n;
	t->pv=l;
	l->n=t;
  	
  	
  }

 void disf()
   {
   	node * p=h;
    while(p!=0){
    	printf("%d\t%s\t%d\n",p->rno,p->name,p->yr);
    p=p->n;
   
    }
   printf("\n");
   
  }
  
  void disb(node *o)
  {
  	 if(o==0)return;
  	 disb(o->n);
  	printf("%d\t%s\t%d\n",o->rno,o->name,o->yr);
  	
  }
  
  

 node * del()
  { 
    int n;
    printf("write rollno to delete\n");
    scanf("%d",&n);
    printf("\n");
    
    node *p=h;
    if(p->rno==n){h=p->n;return h;}
    int i=1;
    while(p!=0){
    if(p->n->rno==n){p->n=p->n->n;p->n->pv=p;return h;}
    p=p->n;
    i++; 
    }
   printf("rno not present\n");
  
  }
  void mod(){
  	node *p=h;
  	int n;
  	printf("write roll no to modify\n");
  	scanf("%d",&n);
  	while(p!=0){
  		if(p->rno==n){
	  printf("\nwrite rollno\twrite name\twrite year\n");
      scanf("%d%s%d",&p->rno,p->name,&p->yr); 		  
	   return;				}
	  p=p->n;	  		  
	  }
  	printf("rollno not present\n");
  	
  }

 

 
int main()
   {
  int n,e=1;
  while(e)
  {
  
    printf("write 0 to exit\nwrite 1 to create\nwrite 2 to display backward\nwrite 3 to displayforward\nwrite 4 for delete\nwrite 5 for modify\nwrite 6 to insert\n");
           scanf("%d",&e);
  
    switch(e) 
  {
    case 1 :h=create(); break;
    case 2 : printf("\nrollno\tname\tyear\n");
	         disb(h); break;
   	case 3 : printf("\nrollno\tname\tyear\n");
	         disf(); break;
    case 4 : del(); break;
    case 5 : mod(); break;
    case 6 : insert();break;
   }
} 
    
  
  
  
  
 return 0; }
  
  
  
   

