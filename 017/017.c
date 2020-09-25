#include <stdio.h>
#include <string.h>
#define num 300

void Add(int *r, int *x, int *y){
    int i,sum,c;
    for(c=i=0;i<num;i++){
        r[i]=x[i]+y[i]+c;
        c=r[i]/10;
        r[i]=r[i]%10;
    }
}

void Sub(int *r, int *x, int *y){
    int i,b;
    for(b=i=0;i<num;i++){
        r[i]=x[i]-y[i]-b;
        if(r[i]<0){
            b=1,r[i]+=10;
        }else{
            b=0;
        }
    }
}

void Mul(int *r, int *x, int *y){
    int i,j,c;
    memset(r,0,sizeof(int)*num);
    for(i=0;i<num;++i){
        if(x[i]==0)
            continue;
        for(j=0;i+j<num;j++)
            r[i+j]+=x[i]*y[j];
    }
    for(c=i=0;i<num;i++){
        r[i]+=c;
        c=r[i]/10;
        r[i]=r[i]%10;
    }
}

int com(int *x, int *y){
    int i=num-1;
    while(i>0 && x[i]==y[i]) i--;
    return x[i]-y[i];
}

int readfromstring(int* big, char* str){
    int i=0, l=strlen(str);
    memset(big, 0, sizeof(int)*num);
    for(i=l-1;i>=0;i--)
        big[l-i-1]=str[i]-'0';
}

void Print(int *big){
    int i=num-1;
    for(i=num-1;i>0 && big[i]==0;i--);
    while(i>=0) printf("%d", big[i]), i--;
}

int main(){
    int i,j,k,l1,l2,f;
    char sn1[num],sn2[num];
    int n1[num],n2[num],n3[num];
    int *x,*y,*z;
    x=n1;y=n2;z=n3;
    scanf("%d",&f);
    scanf("%s",&sn1);
    scanf("%s",&sn2);
    l1=strlen(sn1);
    l2=strlen(sn2);
    readfromstring(x,sn1);
    readfromstring(y,sn2);
    memset(z, 0, sizeof(int)*num);
    if(f==1){
        Add(z,x,y);
        Print(z);
    }else if(f==2){
        if(com(x,y)<0){
            printf("-");
            Sub(z,y,x);
            Print(z);
        }else if(com(x,y)>0){
            Sub(z,x,y);
            Print(z);
        }else
            printf("0");
    }else if(f==3){
        Mul(z,x,y);
        Print(z);
    }
    return 0;
}
