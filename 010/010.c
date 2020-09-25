#include <stdio.h>

double mode1(int num){
	int n,j,sum,d;
    for (j=1,sum=0;num>=1;j=j*10){
        d=num%2;
        sum+=d*j;
        num=num/2;
    }
    printf("%d",sum);
}

double mode2(int num){
	int n,j,sum;
	for(j=1,sum=0;num>=1;j=j*2){
        sum+=(num%10)*j;
        num=num/10;
    }
    printf("%d",sum);
}

double mode3(int a1,int a2,int num){
	int n,j,sum,d;
    int num1;
	for(j=1,sum=0;num>=1;j=j*a1){
		sum+=(num%10)*j;
		num=num/10;
	}
	num1=sum;
	for (j=1,sum=0;num1>=1;j=j*10){
		d=num1%a2;
		sum+=d*j;
		num1=num1/a2;
	}
	printf("%d",sum);
}

int main(){
	int n,j,a1,a2,num,sum,d;
	scanf("%d",&n);
	if (n==1){
        scanf("%d",&num);
        mode1(num);
	}
	else if(n==2){
		scanf("%d",&num);
		mode2(num);
	}
	else if(n==3){
        scanf("%d",&a1);
        scanf("%d",&a2);
        scanf("%d",&num);
        mode3(a1,a2,num);
	}
	return 0;
}
