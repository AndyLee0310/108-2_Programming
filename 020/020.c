#include <stdio.h>
#define N 100000

int test(int str[],int n){
    int i,j,count=0;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(str[i]>str[j])
                count++;
        }
    }
    return count;
}

int main(){
    int n,i,num,x;

    scanf("%d",&n);
    fflush(stdin);

    int str[N];
    for(i=0;i<n;i++){
        scanf(" %d", &num);
        str[i]=num;
    }

    x=test(str,n);
    printf("%d",x);

    return 0;
}
