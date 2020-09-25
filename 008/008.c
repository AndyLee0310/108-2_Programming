#include <stdio.h>

void printMode1(int num){
    int i,j;
    //mode1的第一個圖形
    for(i=1;i<=num;i++){
        for(j=1;j<=i;j++)
            printf("%d",j);
    printf("\n");
    }
    //mode1的第二個圖形
    for(i=0;i<num;i++){
        for(j=num-i;j>=1;j--)
            printf("%d",j);
    printf("\n");
    }
    //mode1的第三個圖形
    for(i=1;i<=num;i++){
        for(j=0;j<i;j++)
            printf("%d",i);
    printf("\n");
    }
}

void printMode2(int n){
    int i,j,k;
    //mode2的第一個圖形
    for(i=0;i<=n;i++){          //顯示層數
        for(j=1;j<=i;j++)       //顯示前半部
            printf("%d",j);
        for(k=i-1;k>0;k--)      //顯示後半部
            printf("%d",k);
    printf("\n");
    }
    //mode2的第一個圖形
    for(i=1;i<n;i++){
        for(j=n-i;j>1;j--)
            printf("_");
        for(j=i;j>0;j--)
            printf("%d",j);
        for(j=2;j<i+1;j++)
            printf("%d",j);
        for(j=n-i;j>1;j--)
            printf("_");
        printf("\n");
    }
    //mode2的第二個圖形
    for(i=n-1;i>0;i--){
        for(j=n-i;j>1;j--)
            printf("_");
        for(j=i;j>0;j--)
            printf("%d",j);
        for(j=2;j<i+1;j++)
            printf("%d",j);
        for(j=n-i;j>1;j--)
            printf("_");
    printf("\n");
    }
}

int main(){
    int num,mode;
    scanf("%d",&mode);
    scanf("%d",&num);
    if(mode==1)
        printMode1(num);
    else if(mode==2)
        printMode2(num);

    return 0;
}
