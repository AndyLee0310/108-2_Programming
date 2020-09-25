#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i=1,j,num,k=0,m;
    char n[8];
    int Gcode[32][32];
    int output[32][32];
    int bit[32];
    do{
        if(i%2==0){
            scanf("%s",&n);
            if(n[0]=='-'&&n[1]=='1')
                break;
        }else{
            scanf("%d %d",&bit[k],&num);
            j=0;
            for(j=bit[k]-1;j>=0;j--){
                m=num%2;
                if(m==0)
                    Gcode[j][k]=0;
                else
                    Gcode[j][k]=1;
                num=num/2;
            }
            output[0][k]=Gcode[0][k];
            for(j=1;j<bit[k];j++){
                output[j][k]=Gcode[j-1][k]^Gcode[j][k];
            }
            k=k+1;
        }
        i+=1;
    }while(1);
    for(j=0;j<k;j++){
        for(m=0;m<bit[j];m++)
            printf("%d",output[m][j]);
        printf("\n");
    }
    return 0;
}
