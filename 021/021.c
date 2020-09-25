#include <stdio.h>
#include <string.h>

void test(char ip[],int op[][500],int d,int *k,int X,int Y,int w){
    int e = w/d,i,j;
    int num=(ip[(*k)]-48);
    (*k)++;
    if(num==2){
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                test(ip,op,d*2,k,X,Y,w);
                X+=e/2;
            }
            X-=e;
            Y+=e/2;
        }
    }else if(num==1 || num==0){
        for(i=Y;i<(Y+e);i++){
            for(j=X;j<(X+e);j++){
                op[i][j]=num;
      	    }
        }
    }
}
void print(int op[][500],int w){
    int aw=1,i,j;
    for(i=0;i<w;i++){
        for(j=0;j<w;j++){
            if(op[i][j]==1){
                printf("%d,%d\n",i,j);
                aw=0;
            }
        }
    }
    if(aw)
        printf("all white\n");
}
int main(){
    char input[10000];
    int op[500][500];
    scanf(" %s",&input);
    int w,p=0;
    scanf(" %d",&w);
    test(input,op,1,&p,0,0,w);
    print(op,w);
}
