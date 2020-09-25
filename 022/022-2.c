#include <stdio.h>
#include <stdlib.h>

int getpass(int* r[],int y,int x){
    int a1=0, a2=0, a3=0, a4=0, a5=0, a6=0, a7=0, a8=0, a9=0, a10=0, a11=0, a12=0;
    int b1=0, b2=0, b3=0, b4=0, b5=0, b6=0, b7=0, b8=0, b9=0, b10=0, b11=0, b12=0;
    int count, i, j;
    if(x-3>=0){
        if(r[x-3][y]){
            a1 = 1;
        }
    }
    if(x-2>=0){
        if(r[x-2][y]){
            a2 = 1;
        }
    }
    if(x-1>=0){
        if(r[x-1][y]){
            a3 = 1;
        }
    }
    if(9>=x+1){
        if(r[x+1][y]){
            a4 = 1;
        }
    }
    if(9>=x+2){
        if(r[x+2][y]){
            a5 = 1;
        }
    }
    if(9>=x+3){
        if(r[x+3][y]){
            a6 = 1;
        }
    }
    if(y-3>=0){
        if(r[x][y-3]){
            a7 = 1;
        }
    }
    if(y-2>=0){
        if(r[x][y-2]){
            a8 = 1;
        }
    }
    if(y-1>=0){
        if(r[x][y-1]){
            a9 = 1;
        }
    }
    if(9>=y+1){
        if(r[x][y+1]){
            a10 = 1;
        }
    }
    if(9>=y+2){
        if(r[x][y+2]){
            a11 = 1;
        }
    }
    if(9>=y+3){
        if(r[x][y+3]){
            a12 = 1;
        }
    }
    if(x-3>=0 && y-3>=0){
        if(r[x-3][y-3]){
            b1 = 1;
        }
    }
    if(x-2>=0 && y-2>=0){
        if(r[x-2][y-2]){
            b2 = 1;
        }
    }
    if(x-1>=0 && y-1>=0){
        if(r[x-1][y-1]){
            b3 = 1;
        }
    }
    if(9>=x+1 && 9>=y+1){
        if(r[x+1][y+1]){
            b4 = 1;
        }
    }
    if(9>=x+2 && 9>=y+2){
        if(r[x+2][y+2]){
            b5 = 1;
        }
    }
    if(9>=x+3 && 9>=y+3){
        if(r[x+3][y+3]){
            b6 = 1;
        }
    }
    if(9>=y+3 && x-3>=0){
        if(r[x-3][y+3]){
            b7 = 1;
        }
    }
    if(9>=y+2 && x-2>=0 ){
        if(r[x-2][y+2]){
            b8 = 1;
        }
    }
    if(9>=y+1 && 0>=x-1){
        if(r[x-1][y+1]){
            b9 = 1;
        }
    }

    if(a1 && a2 && a3 && a4)
        return 1;
    if(a5 && a2 && a3 && a4)
        return 1;
    if(a5 && a6 && a3 && a4)
        return 1;
    if(a7 && a8 && a9 && a10)
        return 1;
    if(a11 && a8 && a9 && a10)
        return 1;
    if(a11 && a12 && a9 && a10)
        return 1;
    if(b1 && b2 && b3 && b4)
        return 1;
    if(b5 && b2 && b3 && b4)
        return 1;
    if(b5 && b6 && b3 && b4)
        return 1;

    i = 1;
    j = 1;
    count = 1;
    while(x-i >=0 && count < 5){
        if(1 == r[x-i][y]){
            i++;
            count++;
            if(count==5){
                return 1;
            }
        }
        else
            break;
    }
    i = 1;
    j = 1;
    count = 1;
    while(x+i <= 9 && count < 5){
        if(1 == r[x+i][y]){
            i++;
            count++;
            if(count==5){
                return 1;
            }
        }
        else
            break;
    }
    i = 1;
    j = 1;
    count = 1;
    while(y+j <= 9 && count < 5){
        if(1 == r[x][y+j]){
            j++;
            count++;
            if(count==5){
                return 1;
            }
        }
        else
            break;
    }
    i = 1;
    j = 1;
    count = 1;
    while(y-j >=0 && count < 5){
        if(1 == r[x][y-j]){
            j++;
            count++;
            if(count==5){
                return 1;
            }
        }
        else
            break;
    }
    i = 1;
    j = 1;
    count = 1;
    while(x-i >=0 && y-j >=0 && count < 5){
        if(1 == r[x-i][y-j]){
            i++;
            j++;
            count++;
            if(count==5){
                return 1;
            }
        }
        else
            break;
    }
    i = 1;
    j = 1;
    count = 1;
    while (x+i <=9 && y+j <= 9 && count < 5){
        if(1 == r[x+i][y+j]){
            i++;
            j++;
            count++;
            if(count==5){
                return 1;
            }
        }
        else
            break;
    }
    i = 1;
    j = 1;
    count = 1;
    while(x-i >=0 &&  y+j <= 9 && count < 5){
        if(1 == r[x-i][y+j]){
            i++;
            j++;
            count++;
            if(count==5){
                return 1;
            }
        }
        else
            break;
    }
    i = 1;
    j = 1;
    count = 1;
    while(x+i <= 9 && y-j >=0 && count < 5){
        if(1 == r[x+i][y-j]){
            i++;
            j++;
            count++;
            if(count==5){
                return 1;
            }
        }
        else
            break;
        }
    return 0;
    }
	
int main(){
    char sc[10][20];
    int ch[10][10];
    int i, j,flag=0;
    int *pch[10];
    for (i = 0; i < 10;i++){
        gets(sc[i]);
        pch[i] = ch[i];
    }
    for (i = 0; i < 10;i++){
        for (j = 0; j < 10;j++)
            ch[i][j] = sc[i][j*2]-'0';
    }
    for (i = 0; i < 10;i++){
        for (j = 0; j < 10;j++){
            if(ch[i][j] == 0){
                if(getpass(pch,j,i)){
                    flag = 1;
                    printf("%d %d\n", i, j);
                }
            }
        }
    }
    if(flag == 0)
        printf("impractical attempt!");
    return 0;
}