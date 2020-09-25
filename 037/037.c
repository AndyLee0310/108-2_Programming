#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Tree{
	char data;
	struct Tree *left;
	struct Tree *right;
}tree;

typedef tree* bTree;

bTree Tree_create(char data){
	bTree Treenew;
	Treenew=(bTree)malloc(sizeof(tree));
	Treenew->left=NULL;
	Treenew->right=NULL;
	Treenew->data=data;
	return Treenew;
}

typedef struct List{
	char data;
	struct List *next;
}list;

typedef list* listp;

listp list_create(char data){
	listp newlist;
	newlist=(listp)malloc(sizeof(list));
	newlist->next=NULL;
	newlist->data=data;
	return newlist;
}

void inb(listp *p,char data){
	listp current,newlist;
	newlist=(listp)malloc(sizeof(list));
	newlist->data=data;
	if(*p==NULL){
		newlist->next=NULL;
		*p=newlist;
	}
	else{
		current=*p;
		while(1){
			if(current->next==NULL){
				newlist->next=NULL;
				current->next=newlist;
				break;
			}
			current=current->next;
		}
	}
}

listp am(listp root,char datatype[]){
	int i,j,a;
	for(i=0;i<strlen(datatype);i++){
		inb(&root,datatype[i]);
	}
	return root;
}

listp fr(listp root,char data){
	listp newlist=NULL;
	while(root->data!=data){
		root=root->next;
	}
	root=root->next;
	while(root!=NULL){
		inb(&newlist,root->data);
		root=root->next;
	}
	return newlist;
} 

listp fl(listp root,char data){
	listp newlist=NULL;
	while(root->data!=data){
		inb(&newlist,root->data);
		root=root->next;
	}
	return newlist;
}

int list_count(listp list){
	int i,j=0;
	while(list!=NULL){
		j++;
		list=list->next;
	}
	return j;
}

listp df(listp list){
	listp newlist=list->next;
	free(list);
	return newlist;
}

listp flP(listp list,int lnum,int rnum){
	listp newlist=NULL;
	int i,j,a;
	for(i=0;i<lnum;i++){
		inb(&newlist,list->data);
		list=list->next;
	}
	return newlist;
}

listp frP(listp list,int lnum,int rnum){
	listp newlist=NULL;
	int i,j,a;
	for(i=0;i<lnum;i++){
		list=list->next;
	}
	for(i=0;i<rnum;i++){
		inb(&newlist,list->data);
		list=list->next;
	}
	return newlist;
}

void listPrint(listp list){
	while(list!=NULL){
		printf("%c ",list->data);
		list=list->next;
	}
	printf("\n");
}

listp delback(listp list,int num){
	listp newlist=NULL;
	int i,j,a;
	if(num==1)return newlist;
	else{
		for(i=0;i<num-1;i++){
			inb(&newlist,list->data);
			list=list->next;
		}
		return newlist;
	}
}

char fbd(listp list){
	while(list->next!=NULL){
		list=list->next;
	}
	return list->data;
}

bTree ftree(bTree tree,char data){
	bTree Treenew=NULL;
	if(tree==NULL) return Treenew;
	else if(tree->data==data){
		Treenew=Tree_create(data);
		Treenew->left=tree->left;
		Treenew->right=tree->right;
		return Treenew;
	}
	else{
		Treenew=ftree(tree->left,data);
		if(Treenew!=NULL)return Treenew;
		Treenew=ftree(tree->right,data);
		if(Treenew!=NULL)return Treenew;
	}
}

void lo(bTree tree,int num){
	int i=0;
	listp list=NULL;
	inb(&list,tree->data);
	bTree TREE=NULL,TREEleft=NULL,TREEright=NULL;
	while(i<num){
		printf("%c",list->data);
		TREE=ftree(tree,list->data);
		if(TREE->left!=NULL) {
			TREEleft=TREE->left;
			inb(&list,TREEleft->data);
		}
		if(TREE->right!=NULL) {
			TREEright=TREE->right;
			inb(&list,TREEright->data);
		}
		list=list->next;
		i++;
	}
}

void mbt1(listp O,listp I,bTree *tree){
	char start;
	int lnum,rnum,Onum;
	bTree TREE=NULL;
	listp leftI=NULL,rightI=NULL,leftO=NULL,rightO=NULL;
	if(list_count(O)==1){
		*tree=Tree_create(O->data);
	}
	else{
		start=fbd(O);
		Onum=list_count(O);
		O=delback(O,Onum); 
		*tree=Tree_create(start);
		leftI=fl(I,start);
		rightI=fr(I,start);
		lnum=list_count(leftI);
		rnum=list_count(rightI);
		leftO=flP(O,lnum,rnum);
		rightO=frP(O,lnum,rnum);
		if(lnum!=0) mbt1(leftO,leftI,&((*tree)->left));
		if(rnum!=0) mbt1(rightO,rightI,&((*tree)->right));
	}
}

void mbt2(listp P,listp I,bTree *tree){
	char start;
	int lnum,rnum;
	bTree TREE=NULL;
	listp leftI=NULL,rightI=NULL,leftP=NULL,rightP=NULL;
	if(list_count(P)==1){
		*tree=Tree_create(P->data);
	}
	else{
		start=P->data;
		P=df(P);
		*tree=Tree_create(start);
		leftI=fl(I,start);
		rightI=fr(I,start);
		lnum=list_count(leftI);
		rnum=list_count(rightI);
		leftP=flP(P,lnum,rnum);
		rightP=frP(P,lnum,rnum);
		if(lnum!=0) mbt2(leftP,leftI,&((*tree)->left));
		if(rnum!=0) mbt2(rightP,rightI,&((*tree)->right));
	}
}

void io(bTree root){
	if(root!=NULL){
		io(root->left);
		printf("%c ",root->data);
		io(root->right);
	}
}

int main(){
	listp I=NULL,P=NULL,O=NULL;
	bTree TREE=NULL;
	int num,i;
	char it[2],o[100],t[100];
	for(i=0;i<2;i++){
		scanf("%c",&it[i]);
		getchar();
		if(i==0) {
			scanf("%[^\n]",o);		
			getchar();
		}
		else {
			scanf("%[^\n]",t);
			getchar();
		}
	}
	for(i=0;i<2;i++){
		switch(it[i]){
			case 'P':
				if(i==0)P=am(P,o);
				else P=am(P,t);
				break;
			case 'I':
				if(i==0)I=am(I,o);
				else I=am(I,t);
				break;
			case 'O':
				if(i==0)O=am(O,o);
				else O=am(O,t);
				break;
		}
	}
	num=list_count(I);
	if (P==NULL){
		mbt1(O,I,&TREE); 
	}
	else if (O==NULL){
		mbt2(P,I,&TREE); 
	}
	lo(TREE,num);
	return 0;
} 
 
