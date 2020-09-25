#include <stdio.h>
#define N 100

void printCube1(int x[][N],int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ",x[i][j]);
        printf("\n");
    }
}

void printCube2(int x[][N],int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=n-1;j>=0;j--)
            printf("%d ",x[j][i]);
        printf("\n");
    }
}

void printCube3(int x[][N],int n){
    int i,j;
    for(i=n-1;i>=0;i--){
        for(j=0;j<n;j++)
            printf("%d ",x[j][i]);
        printf("\n");
    }
}

void printCube4(int x[][N],int n){
    int i,j;
    for(i=n-1;i>=0;i--){
        for(j=0;j<n;j++)
            printf("%d ",x[i][j]);
        printf("\n");
    }
}

void main(){
    int i,j;
    int m=1;

    int x[N][N],n,num;
    scanf("%d",&n);
    scanf("%d",&num);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            x[i][j]=m++;
    }

    if(num==1)
        printCube1(x,n);
    else if(num==2)
        printCube2(x,n);
    else if(num==3)
        printCube3(x,n);
    else if(num==4)
        printCube4(x,n);
}
