#include <stdio.h>
#include <string.h>
#define LEN 200

void Add(char a[], char b[], char c[]){
    int i;
    for(i=0; i<LEN; i++)
        c[i]=a[i]+b[i];
    for(i=0; i<LEN-1; i++) {
        if(c[i]>=10) {
            c[i+1]+=c[i]/10;
            c[i]=c[i]%10;
        }
    }
}

void Sub(char a[], char b[], char c[]){
    int i;
    for(i=0; i<LEN; i++)
        c[i]=a[i]-b[i];
    for(; i>=0; i--){
        if(c[i]<0){
            c[i+1]=c[i+1]-1;
            c[i]=10+c[i];
        }
    }
}

void Mul(char a[], char b[], char c[]){
    int i, j;
    for(i=0; i<LEN*2; i++)
        c[i]=0;
    for(i=0; i<LEN; i++) {
        for(j=0; j<LEN; j++) {
            c[i+j]+=a[j]*b[i];
            if(c[i+j]>=10) {
                c[i+j+1]+=c[i+j]/10;
                c[i+j]=c[i+j]%10;
            }
        }
    }
}

int Input(char n[]){
    char s[LEN];
    int i, l;
    for(i=0; i<LEN; i++)
        n[i]=0;
    if(scanf("%s", s)<1) return -1;
        l=strlen(s);
    for(i=0; i<l; i++)
        n[i]=s[l-i-1]-'0';
    return 0;
}

void Print(char n[]){
    int i;
    for(i=LEN-1; i>0; i--)
        if(n[i]!=0) break;
    for(; i>=0; i--)
        printf("%d", n[i]);
    printf("\n");
}

void main(){
    int n;
    char a[LEN], b[LEN], c[LEN*2];
    scanf("%d",&n);
    Input(a);
    Input(b);
    if(n==1)
        Add(a, b, c);
    else if(n==2)
        Sub(a, b, c);
    else if(n==3)
        Mul(a, b, c);
    Print(c);
}
