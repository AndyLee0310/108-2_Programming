#include<stdio.h>
typedef struct p{
    int n;
    int d;
    int b;
    int ns[100];
}p_t;
typedef struct w{
    int num;
    p_t data[100];
}w_t;

int max(int alldy[],int nums){
    int m=0,j;
    for(j=0;j<nums;j++){
        if (alldy[j]>m)m=alldy[j];
    }
    return m;
}
int cd(w_t project,int now,int next[]){
    int alldy[100];
    if(project.data[next[0]-1].b==0)return (project.data[now].d+project.data[next[0]-1].d);
    for(int j=0;j<project.data[now].b;j++){
        alldy[j]=cd(project,next[j]-1,project.data[next[j]-1].ns);
    }
    return project.data[now].d+max(alldy,project.data[now].b);
}
int main(){
    w_t project;
    int x=0,s;
    scanf(" %d",&x);
    for(int i=0;i<x;i++){
        scanf(" %d",&project.num);
        for(int j=0;j<project.num;j++){
            project.data[j].n=j;
            scanf(" %d",&project.data[j].d);
            scanf(" %d",&project.data[j].b);
            for(int a=0;a<project.data[j].b;a++){
                scanf(" %d",&project.data[j].ns[a]);
            }
        }
        s=0;
        printf("%d\n",cd(project,s,project.data[s].ns));
    }
    return 0;
}

