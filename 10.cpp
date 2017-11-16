#include<stdio.h>
#include<stdlib.h>
struct node{
	int cf;
	int ex;
	struct node *n;
};
typedef struct node node;
 int size=sizeof(node);
  node* create()
  { int n;
   printf("write terms in your plynomial\n");  
   scanf("%d",&n);
    if(n==0){return 0;}    
   node *h=(node*)malloc(size);
   node *c=h;	
     while(n--){
   	printf("coefficient|power\n");
   	scanf("%d%d",&c->cf,&c->ex);
   if(n==0)break;
	c->n=(node*)malloc(size); 
    c=c->n;
	 }	
  	c->n=0;
  	return h;
  }

 void dis(node *h){
 	if(h==0)return ;
 	printf("%dX^%d",h->cf,h->ex);
	h=h->n;
	while(h!=0)
	{
 	printf("+%dX^%d",h->cf,h->ex);
    h=h->n;
	}
 	printf("\n");
 	
 }
 node *add(node *h1,node *h2)
 {  node *p=h1;
    node *q=h2;
 	node * h=0;
	node *c=h;
	if(h1==0&&h2==0)return 0;
  
       while(p!=0&&q!=0){
       if(c==0){
       	h=(node *)malloc(size);
       	c=h;
	   }
	   else {
	   	c->n=(node *)malloc(size);
	   	c=c->n;
	     c->n=0;
	   }
	   	
      if(p->ex==q->ex){
     	c->ex=p->ex;
     	c->cf=p->cf+q->cf;
     	p=p->n;
     	q=q->n;
	  
	  }	else if(p->ex>q->ex)
	 {   c->ex=p->ex;
	     c->cf=p->cf;
         p=p->n;
	    
	 }
	  else if(p->ex<q->ex) 
	 {   c->ex=q->ex;
	     c->cf=q->cf;
	     q=q->n;
	 }	  	
    	
	}
	
	 if(p==0){

	 while(q!=0){
        if(c==0){
       	h=(node *)malloc(size);
       	c=h;
	   }
	   else {
	   	c->n=(node *)malloc(size);
	   	c=c->n;
	     c->n=0;
	   }



	   c->cf=q->cf;
	   c->ex=q->ex;
	   q=q->n; 
	 } c->n=0; }
	 if(q==0){
	 while(p!=0){
        if(c==0){
       	h=(node *)malloc(size);
       	c=h;
	   }
	   else {
	   	c->n=(node *)malloc(size);
	   	c=c->n;
	     c->n=0;
	   }

	   c->cf=p->cf;
	   c->ex=p->ex;
	   p=p->n; 
	 } c->n=0; }
	 
	 
	 
	 
    c->n=0;
 	return h;
 	
 	
 }
  node * smul(node * h,node a) {
  	  node *p=(node *)malloc(size);
      node * head=p;
	  while(h!=0)
	  {
  		p->cf=(h->cf)*(a.cf);
  		p->ex=(h->ex)+(a.ex);
  		h=h->n;
	    if(h==0)break;
  		p->n=(node *)malloc(size);
	    p=p->n;
	  }
     p->n=0;
     return head;
  }
  
  node * mul(node * h1,node *h2)
  {     node *p=0;
        node *h;
		while(h1!=0){
       	h=smul(h2,*h1);
       	p=add(p,h);
       	h1=h1->n;
	   }    	
   	
  	return p;
  	
  }
 
 

int main(){
	node *h1,*h2,*r;
	r=0;
	int e=1;
	while(e){
printf("press:-\n0-to exit\n1-to input\n2-to display\n3-to add\n4-to multiply\n");
scanf("%d",&e);		
	switch(e)
	{
		case 1:h1=create();
		       h2=create();
		       break;
		case 2:dis(h1);
		       dis(h2);
		       break;
		case 3:r=add(h1,h2);
		       dis(r);
			   break;
		case 4:r=mul(h1,h2);
		       dis(r);
			   break;
		
	}
	
	}
	
	return 0;
}
