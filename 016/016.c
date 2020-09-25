#include <stdio.h>

int getnum(char a){
    char n[10]={'0','1','2','3','4','5','6','7','8','9'};
    int i;
    for(i=0;i<10;i++){
        if(a==n[i])
            break;
    }
    return i;
}

int getlen(char *b){
    int i=0;
    while(b[i] != '\0'){
        i+=1;
    }
    return i;
}

int main(){
    int i,j,k,n,f,c=0,x;
    char b[128];
    int num[128];
    scanf("%s",b);
    scanf("%d",&n);
    k=getlen(b);
    for(i=0;i<k;i++){
            num[i]=getnum(b[i]);
    }
    x=k-n+1;
    for(i=0;i<x;i++){
        f=1;
        for(j=i;j<i+n;j++){
            for(k=j+1;k<i+n;k++){
                if(num[j]==num[k]){
                    f=0;
                    break;
                }
            }
            if(f==0)
                break;
        }
        if(f==1)
            c++;
    }
    printf("%d",c);
    return 0;
}
