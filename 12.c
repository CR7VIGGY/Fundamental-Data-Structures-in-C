#include<stdio.h>
#include<stdlib.h>

struct node{
	int d;
	struct node *n;
	struct node *h;
};

typedef struct node node;
 int size=sizeof(node);
  node *create()
  {
  	int e=1;
  	node *temp;
  	node *head=0;
    node *curr=head;
	int flag=0;
	
	while(e||flag){
	printf("press->  1 for head node  |  2 for normal node  |  0 when done\n");
    scanf("%d",&e);
	if(e)
	{
	 if(e==1)
	 {
	 	if(!flag)
	 	{
	 	    flag=1;temp=curr;
	 	}
	 	
	        curr->h=(node *)malloc(size);
	        curr=curr->h;curr->n=0;curr->h=0;	
	        printf("write data\t");
	        scanf("%d",&curr->d);
	 }
	 else
	 {
	  if(curr==0){
	    head=(node *)malloc(size);	
	    curr=head;
	    curr->n=0;curr->h=0;
	    printf("write data\t");
	    scanf("%d",&curr->d); 
	     
	  }
	  else
	  {
	    curr->n=(node *)malloc(size);
	    curr=curr->n; 	
	     printf("write data\t");
	     scanf("%d",&curr->d); 	
	     curr->h=0;curr->n=0;
	  }
	 
	 
	 
	  }
	 
	}
	 if(!e&&flag){
   	 curr=temp;e=1;
   	 flag=0;
   }
	 
  }
   
  	return head;
  }

 void dish(node *h,int s){
 	if(h==0)return;
 	printf("%d.%d ",s,h->d);
 	dish(h->n,s);
	if(h->h!=0){printf("\n  ");dish(h->h,h->d);}
 }
 void disv(node *h){
 	
 	if(h==0)return;
   	printf("\n%d",h->d);
	if(h->h!=0){printf("\n ");dish(h->h,h->d);}
	disv(h->n);
 }

int main(){
	int e=1;
    node *h=0; 
	while(e){
	printf("press:-\n0-to exit\n1-to create\n2-todisplay\n");
	scanf("%d",&e);
	switch(e){
	case 1:h=create();
	       break;	
	case 2:disv(h);
	       break;
		
	}
	}
	
	
	return 0;
}
