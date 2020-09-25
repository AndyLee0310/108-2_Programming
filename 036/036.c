#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct List{
	char name[100];
	int age,birth[3];
	struct List *next;
}list;

typedef list* lp;

void insertfront(lp *p,char name[],int age,int birth[]){
	int i,j,a;
	lp listnew;
	listnew=(lp)malloc(sizeof(list));
	strcpy(listnew->name,name);
	listnew->age=age;
	for(j=0;j<3;j++)listnew->birth[j]=birth[j];
	if(*p==NULL){
		listnew->next=NULL;
		*p=listnew;
	}else{
		listnew->next=*p;
		*p=listnew;
	}
}

int main(){
	int	it=4,it2,j;
	lp tp=NULL,tp2=NULL;
	while(1){
		char namein[100]={};
		int gaein=0,birthin[3]={};
		scanf(" %d",&it);
		if(it==3){
			break;
		}else if(it==1){
			scanf(" \"%[^\"]",&namein);
			getchar();
			scanf(" %d",&gaein);
			for(j=0;j<3;j++)scanf(" %d",&birthin[j]);
			insertfront(&tp,namein,gaein,birthin);
		}else if(it==2){
			scanf(" %d",&it2);
			if(tp==NULL){
				printf("The Stack is empty\n");
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
