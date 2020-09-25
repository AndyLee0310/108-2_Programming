#include <stdio.h>
#include <stdlib.h>

int main(){
    char in[18][18];
    int a,b,i,j,c=0,m,out=0,e=1;
    for(i=0;i<18;i++){
        for(j=0;j<18;j++){
            in[i][j] = 'w';
        }
    }

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            scanf(" %c",&in[i+4][j+4]);
        }
    }
    for(i=4;i<14;i++){
        for(j=4;j<14;j++){
            out = 0;
            if(in[i][j]=='0'){
                for(m=4;m>=0;m--){
                    c = 0;
                    a = i-m;
                    b = j-m;
                    while(a<=i-m+4&&b<=j-m+4){
                        if(in[a][b]=='1')   c++;
                        a++;
                        b++;
                    }
                    if(c==4)    out = 1;
                }
                for(m=4;m>=0;m--){
                    c = 0;
                    a = i-m;
                    b = j+m;
                    while(a<=i-m+4&&b>=j-m-4){
                        if(in[a][b]=='1')   c++;
                        a++;
                        b--;
                    }
                    if(c==4)    out = 1;
                }
                for(m=4;m>=0;m--){
                    c = 0;
                    b = j-m;
                    for(b;b<j-m+5;b++){
                        if(in[i][b]=='1')   c++;
                    }
                    if(c==4)    out = 1;
                }
                for(m=4;m>=0;m--){
                    c = 0;
                    a = i-m;
                    for(a;a<i-m+5;a++){
                        if(in[a][j]=='1')   c++;
                    }
                    if(c==4)    out = 1;
                }
            }
            if(out==1){
                printf("%d %d\n",i-4,j-4);
                e = 0;
            }
        }
    }
    if(e==1){
        printf("impractical attempt!\n");
    }
    return 0;
}
