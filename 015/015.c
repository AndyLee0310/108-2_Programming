#include <stdio.h>
#include <math.h>

int getGCD(int a,int b){
    return b?getGCD(b,a%b):a;
    /*
    if(b)
        return gatGCD(b,a%b);
    else
        return a;
    */
}

int symboFunction(int a1,int a2,int b1,int b2,char symbo){
    int a_ans,b_ans;
    switch (symbo){
    case '+':
        a_ans=a1*b2+b1*a2;
        b_ans=a2*b2;
        break;
    case '-':
        a_ans=a1*b2-b1*a2;
        b_ans=a2*b2;
        break;
    case '*':
        a_ans=a1*b1;
        b_ans=a2*b2;
        break;
    case '/':
        a_ans=a1*b2;
        b_ans=a2*b1;
        break;
    }
    symplify(a_ans,b_ans);
}

int symplify(int x,int y){
    int s=getGCD(x,y);
    x /= s;
    y /= s;
    if(x*y<0) printf("-");
    x=abs(x);
    y=abs(y);
    if(x==0){
        printf("0\n");
    }else if(x<y){
        printf("%d/%d\n",x,y);
    }else if(x%y==0){
        printf("%d\n",x/y);
    }else if(x>y){
        printf("%d(%d/%d)\n",x/y,x%y,y);
    }
}
int main(){
    char symbo,word;
    int a1,a2,b1,b2;

    while(word!='n'){

        scanf("%d/%d",&a1,&a2);
        scanf("%d/%d",&b1,&b2);
        scanf("%*c%c%*c",&symbo);

//        scanf("%d/%d%d/%d%*c%c%*c", &a1, &a2, &b1, &b2, &symbo);
        if(a2==0 || b2==0){
            printf("ERROR");
            break;
        }
        symboFunction(a1, a2, b1, b2, symbo);
//        scanf("%c%*c", &word);
        scanf("%c%*c",&word);
    }
    return 0;
}
