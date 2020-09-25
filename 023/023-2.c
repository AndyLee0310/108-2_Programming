#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long mymin=10000000,total=0;
int direction=0;

void swap(char* x, char* y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r,int* in,int width){
    int i,j,s=0,k=1,x=0,y=0,total=0;
    if (l == r){
        while(s<width-1){
            if(direction%2==0){
                total += *(in+x*width+(*(a+k)-48));
                y = *(a+k)-48;
            }
            else{
                total += *(in+(*(a+k)-48)*width+y);
                x = *(a+k)-48;
            }
            s++;
            k++;
            direction++;
        }
        if(total<mymin) mymin = total;
    }
    else {
        for (i = l; i <= r; i++) {
            swap((a + l), (a + i));
            permute(a, l + 1, r,in,width);
            swap((a + l), (a + i)); // backtrack
        }
    }
}

int main(){
    char str[10];
    memset(str,'\0',10);
    int width,x=0,i,j;
    scanf(" %d",&width);
    int in[width][width];
    for(i=0;i<width;i++){
        for(j=0;j<width;j++){
            scanf(" %d",&in[i][j]);
        }
    }
    while(x<width){
        str[x] = x+48;
        x++;
    }
    int n=strlen(str);
    permute(str, 1, n - 1,in,width);
    printf("%d\n",mymin);
    return 0;
}
