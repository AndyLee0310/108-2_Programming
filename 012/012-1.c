#include <stdio.h>

int GCode(int n,int k){
    if(n==1) return k;
    if(k<pow(2,n-1)){
        printf("0");
        return GCode(n-1,k);
    }
    if(k>=pow(2,n-1)){
        printf("1");
        return GCode(n-1,pow(2,n)-1-k);
    }
}

int main(){
    int i=0,n,k;

    while(i==0){
        scanf("%d %d",&n,&k);
        printf("%d\n",GCode(n,k));
        scanf("%d",&i);
        if(i==-1)
            break;
    }

    return 0;
}
