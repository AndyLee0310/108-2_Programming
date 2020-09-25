#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct List{
	char name[100];
	int age,birth[3];
	struct List *next;
}list;

typedef list* listp;

void inft(listp *p,char name[],int age,int birth[]){
	int i;
	listp Listnew;
	Listnew=(listp)malloc(sizeof(list));
	strcpy(Listnew->name,name);
	Listnew->age=age;
	for(i=0;i<3;i++)Listnew->birth[i]=birth[i];
	if(*p==NULL){
		Listnew->next=NULL;
		*p=Listnew;	
	}
	else {
		Listnew->next=*p;
		*p=Listnew;
	} 
}

void inbk(listp *p,char name[],int age,int birth[]){
	int i;
	listp cuet,Listnew;
	Listnew=(listp)malloc(sizeof(list));
	Listnew->next=NULL;
	Listnew->age=age;
	for(i=0;i<3;i++){
		Listnew->birth[i]=birth[i];
	}
	strcpy(Listnew->name,name);
	if(*p==NULL){
		*p=Listnew;
	}else{
		cuet=*p;
		while(1){
			if(cuet->next==NULL){
				cuet->next=Listnew;
				break;
			}
			cuet=cuet->next;
		}
	}
}

int main(){
	int i,j,a,it=4,it2;
	listp tp=NULL,tp2=NULL;
	while(1){
		char inname[100]={};
		int inage=0,inbrith[3]={};
		scanf(" %d",&it);
		if(it==3){
			break;
		}else if(it==1){
			scanf(" \"%[^\"]",&inname);
			getchar();
			scanf(" %d",&inage);
			for(i=0;i<3;i++)scanf(" %d",&inbrith[i]);
			inbk(&tp,inname,inage,inbrith);
		}else if(it==2){
			scanf(" %d",&it2);
			if(tp==NULL){
				printf("The Queue is empty\n");
				continue;
			}
			switch(it2){
				case 1:
					printf("%s\n",tp->name);
					tp2=tp;
					free(tp);
					tp=tp2->next;
					break;
				case 2:
					printf("%d\n",tp->age);
					tp2=tp;
					free(tp);
					tp=tp2->next;
					break;
				case 3:
					printf("%d_%d_%d\n",tp->birth[0],tp->birth[1],tp->birth[2]);
					tp2=tp;
					free(tp);
					tp=tp2->next;
					break;
			}
		}	
	}
	return 0;
}
