#include <stdio.h>

double getisPrimt(int num){
    int i,j,m,n=0;
    for(i=2;i<=num;i++){
        m=0;
        for(j=1;j<=num;j++){
            if(i%j==0)
                m+=1;       //也可以用   m++
            if(m>2)
                break;
        }
            if(m<=2){
                n+=1;       //也可以用   n++
                if(n%3==0 && n>=3)
                    printf("%d\n",i);
            }
    }
    if(n<3)
        printf("含括的質數未達三個");
}

int main(){
    int num;
    scanf("%d",&num);
    if((num>=1)&&(num<=100))
        getisPrimt(num);

    return 0;
}
