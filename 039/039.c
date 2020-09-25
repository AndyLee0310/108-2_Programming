#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Tree {
	int data;
	struct Tree *left;
	struct Tree *right;
} tree;

typedef tree* btree;

btree crtTree(int data) {
	btree Treenew;
	Treenew=(btree)malloc(sizeof(tree));
	Treenew->data=data;
	Treenew->left=NULL;
	Treenew->right=NULL;
	return Treenew;
}

void inTree(btree *TREE,int data) {
	btree Treenew=crtTree(data);
	if(*TREE==NULL) {
		*TREE=Treenew;
	} else {
		btree current=*TREE;
		while(1) {
			if(data<current->data) {
				if(current->left==NULL) {
					current->left=Treenew;
					break;
				}
				current=current->left;
			} else {
				if(current->right==NULL) {
					current->right=Treenew;
					break;
				}
				current=current->right;
			}
		}
	}
}

void pder(btree TREE,int *num) {
	if(TREE!=NULL) {
		printf("%d",TREE->data);
		if(*num!=0)printf(",");
		*num=*num-1;
		pder(TREE->left,num);
		pder(TREE->right,num);
	}
}

void inder(btree TREE,int *num) {
	if(TREE!=NULL) {
		inder(TREE->left,num);
		printf("%d",TREE->data);
		if(*num!=0)printf(",");
		*num=*num-1;
		inder(TREE->right,num);
	}
}

void porder(btree TREE,int *num) {
	if(TREE!=NULL) {
		porder(TREE->left,num);
		porder(TREE->right,num);
		printf("%d",TREE->data);
		if(*num!=0)printf(",");
		*num=*num-1;
	}
}

btree fTree(btree tree,int data) {
	btree Treenew=NULL;
	if(tree==NULL) return Treenew;
	else if(tree->data==data) {
		Treenew=crtTree(data);
		Treenew->left=tree->left;
		Treenew->right=tree->right;
		return Treenew;
	} else {
		Treenew=fTree(tree->left,data);
		if(Treenew!=NULL)return Treenew;
		Treenew=fTree(tree->right,data);
		if(Treenew!=NULL)return Treenew;
	}
}

void fbigest(btree tree,int *data) {
	if(tree!=NULL) {
		if(tree->data>*data)*data=tree->data;
		fbigest(tree->left,data);
		fbigest(tree->right,data);
	}
}

void fmallest(btree tree,int *data) {
	if(tree!=NULL) {
		if(tree->data<*data)*data=tree->data;
		fmallest(tree->left,data);
		fmallest(tree->right,data);
	}
}

int flt(btree tree,int list[],int *changeitem) {
	int max=tree->data;
	fbigest(tree,&max);
	btree change=fTree(tree,max);
	if(change->left==NULL&&change->right==NULL) {
		*changeitem=max;
		return 1;
	}
}

int frl(btree tree,int list[],int *changeitem) {
	int min=tree->data;
	fmallest(tree,&min);
	btree change=fTree(tree,min);
	if(change->left==NULL&&change->right==NULL) {
		*changeitem=min;
		return 1;
	}
}

void delleaf(btree *tree,btree *pre,int data) {
	btree current=*tree;
	btree previous=*pre;
	if(current!=NULL) {
		if(current->data==data){
			if(previous->data>current->data)previous->left=NULL;
			else if(previous->data<current->data)previous->right=NULL;
			free(current);
		}else {
			delleaf(&current->left,&current,data);
			delleaf(&current->right,&current,data);
		}
	}
}

int fnlleaf(btree tree,btree *changetree,int list[],int *changeitem){
	int max=tree->data;
	fbigest(tree,&max);
	*changetree=fTree(tree,max);
	btree change=*changetree;
	if(change->left!=NULL||change->right!=NULL) {
		*changeitem=max;
		return 1;
	}
}

void delprt(btree *tree,btree *pre,btree changetree,int data){
	btree current=*tree;
	btree previous=*pre;
	if(current!=NULL) {
		if(current->data==data){
			if(previous->data>current->data)previous->left=changetree->left;
			else if(previous->data<current->data)previous->right=changetree->left;
			free(current);
		}else {
			delprt(&current->left,&current,changetree,data);
			delprt(&current->right,&current,changetree,data);
		}
	}
}

int fnrleaf(btree tree,btree *changetree,int list[],int *changeitem){
	int min=tree->data;
	fmallest(tree,&min);
	*changetree=fTree(tree,min);
	btree change=*changetree;
	if(change->left!=NULL||change->right!=NULL) {
		*changeitem=min;
		return 1;
	}
}

void delpart1(btree *tree,btree *pre,btree changetree,int data){
	btree current=*tree;
	btree previous=*pre;
	if(current!=NULL) {
		if(current->data==data){
			if(previous->data>current->data)previous->left=changetree->right;
			else if(previous->data<current->data)previous->right=changetree->right;
			free(current);
		}else {
			delpart1(&current->left,&current,changetree,data);
			delpart1(&current->right,&current,changetree,data);
		}
	}
}

void delTree(btree *TREE,int data) {
	btree current=*TREE;
	btree previous=*TREE;
	btree changetree=NULL;
	int ans[100]= {},check=0,changeitem;
	while(current!=NULL) {
		if(current->data==data) {
			if(current->left==NULL&&current->right==NULL) {
				if(previous->data>current->data)previous->left=NULL;
				else if(previous->data<current->data)previous->right=NULL;
				free(current);
				break;
			}
			else {
				if(current->left!=NULL){
					check=flt(current->left,ans,&changeitem);
					if(check==1) {
						delleaf(TREE,TREE,changeitem);
						current->data=changeitem;
						break;
					}
					check=0;
				}
				check=frl(current->right,ans,&changeitem);
				if(check==1) {
					delleaf(TREE,TREE,changeitem);
					current->data=changeitem;
					break;
				}
				check=0;
				if(current->left!=NULL){
					check=fnlleaf(current->left,&changetree,ans,&changeitem);
					if(check==1) {
						delprt(TREE,TREE,changetree,changeitem);
						current->data=changeitem;
						break;
					}
					check=0;
				}
				check=fnrleaf(current->right,&changetree,ans,&changeitem);
				if(check==1) {
					delpart1(TREE,TREE,changetree,changeitem);
					current->data=changeitem;
					break;
				}
				check=0;
			}
		}else {
			if(data<current->data) {
				previous=current;
				current=current->left;
			} else if(data>current->data) {
				previous=current;
				current=current->right;
			}
		}
	}
}

int main() {
	int i=0,j=0,deldt,n;
	int input[100]= {};
	btree TREE=NULL;
	while(1) {
		j++;
		scanf("%d",&input[i]);
		n=getchar();
		if(n==10)break;
		i++;
	}
	scanf("%d",&deldt);
	getchar();
	for(i=0; i<j; i++) {
		inTree(&TREE,input[i]);
	}
	int num=j-2;
	delTree(&TREE,deldt);
	printf("preorder:");
	pder(TREE,&num);
	printf("\n");
	num=j-2;
	printf("inorder:");
	inder(TREE,&num);
	printf("\n");
	num=j-2;
	printf("postorder:");
	porder(TREE,&num);

	return 0;
}
