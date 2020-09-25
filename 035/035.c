#include<stdio.h>
#include<stdlib.h>

typedef struct List{
	int data;
	struct List *next;
}list;

typedef list* lp;

lp crt(int data){
	lp listnew;
	listnew=(lp)malloc(sizeof(list));
	listnew->data=data;
	listnew->next=NULL;
	return listnew;
}

void inf(lp *p,int data){
	lp listnew=crt(data);
	if((*p)==NULL){
		listnew->next=NULL;
		(*p)=listnew;
	}
	else{
		listnew->next=(*p);
		(*p)=listnew;
	}
}
void nullmake(lp *p,int num){
	int i;
	for(i=0;i<num;i++){
		inf(p,0);
	}
}

void inb(lp *p,int data){
	lp listnew=crt(data);
	lp cut=(*p);
	if((*p)==NULL){
		(*p)=listnew;
	}
	else{
		while(cut->next!=NULL){
			cut=cut->next;
		}
		cut->next=listnew;
	}
}

void align(lp *p,int num,int until){
	lp cut=(*p);
	while(num!=until){
		inb(&cut,0);
		num++;
	}
} 

void putdatainlist(lp *list,int num,int data){
	int i,n=0;
	lp cut=*list;
	for(i=0;i<num;i++){
		cut=cut->next;
	}
	cut->data+=data;
}

void Sub(lp *p1,lp *p2,int n1,int n2,int ng,int ans[]){
	int i,j,a;
	lp fc1=*p1;
	lp fc2=*p2;
	for(i=0;i<ng;i++){
		ans[i]=fc1->data-fc2->data;
		fc1=fc1->next;
		fc2=fc2->next; 
	}
} 

void Mul(lp *p1,lp *p2,int n1,int n2,int ng,lp *ans){
	int i,j,a;
	lp fc1=*p1;
	lp fc2=*p2;
	for(i=0;i<ng;i++){
		for(j=0;j<ng;j++){
			putdatainlist(ans,99-(i+j),fc1->data*fc2->data);
			fc2=fc2->next;
		}
		fc2=*p2;
		fc1=fc1->next;
	}
} 

void Add(lp *p1,lp *p2,int n1,int n2,int ng,int ans[]){
	int i,j,a;
	lp fc1=*p1;
	lp fc2=*p2;
	for(i=0;i<ng;i++){
		ans[i]=fc1->data+fc2->data;
		fc1=fc1->next;
		fc2=fc2->next; 
	}
}

void PrintList(lp list){
	int a=0;
	while(list!=NULL){
		if(list->data!=0||a==1){
			printf("%d ",list->data);
			a=1;
			}
		if(list->next==NULL&&a==0)printf("0");
		list=list->next;
		
	}
	printf("\n");
}

void Print(int list[],int num){
	int a=1,i;
	for(i=num;i>=0;i--){
		if(list[i]!=0)a=0;
		if(a==1&&i==0)printf("%d",0);
		if(a==1)continue;
		printf("%d ",list[i]);
	}
	printf("\n");
}

int main(){
	lp fc1=NULL,fc2=NULL,ans3=NULL;
	int m,m1=0,m2=0,n,na,as1[100]={},as2[100]={};
	nullmake(&ans3,100);
	while(1){
		scanf(" %d",&m);
		inf(&fc1,m);
		m1++;
		n=getchar();
		if(n==10)break;
	}
	while(1){
		scanf(" %d",&m);
		inf(&fc2,m);
		m2++;
		n=getchar();
		if(n==10)break;
	}
	if(m1<m2){
		align(&fc1,m1,m2);
		na=m2;
	}
	else if(m2<m1){
		align(&fc2,m2,m1);
		na=m1;
	}
	else na=m1;
	Add(&fc1,&fc2,m1,m2,na,as1);
	Sub(&fc1,&fc2,m1,m2,na,as2);
	Mul(&fc1,&fc2,m1,m2,na,&ans3);
	Print(as1,na-1);
	Print(as2,na-1);
	PrintList(ans3);

	return 0;
}
