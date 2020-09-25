#include <stdio.h>

int main()
{
    int i,j,state=0,outtime=0,homerun=0;    //int home=0;
    char members[5];

    for (i=0;i<5;i++){
        scanf(" %c",&members[i]);
    }
    for (j=0;j<5;j++){
        if (members[j]=='O'){
            outtime+=1;
        }
        if (outtime==3){
            outtime=0;
            state=0;
            break;
        }
        else{
            if(members[j]=='1'){    //home=1;
                state=(state<<1)|(1<<0);    //state=(state<<home)|(1<<(home-1))
                state=state&7;
            }else if(members[j]=='2'){
                state=(state<<2)|(1<<1);
                state=state&7;
            }else if(members[j]=='3'){
                state=(state<<3)|(1<<2);
                state=state&7;
            }else if(members[j]=='H'){
                state=(state<<4)|(1<<3);
                state=state&7;
            }
        }
    }
    printf("%d\n",state&1);
    printf("%d\n",(state>>1)&1);
    printf("%d",(state>>2)&1);
    return 0;
}
