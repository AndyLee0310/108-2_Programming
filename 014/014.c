#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int giveback(int num){
	int count=0;
	while(num != 1){
		if(num == 0){
			count=0;
			break;
			}
			if(num % 2 == 0){
				num=num/2;
				count=count+1;
			}
			else{
				num=(num+1)/2;
				count=count+1;
			}
		}
	return count;
}
int getnum(char c){
	if(c == '1')
		return 1;
	else
		return 0;
}
int test(int n){
	int result=1,i;
	if( n == 0 )
		result = 128;
	else{
		for(i=0;i<(7-n);i++){
			result=result*2;
		}
	}
	return result;
}

int main(){
	int c,i,num,j=0,k,x,y,sum;
	char n[8];
	char out[11][32];
	do{
		num= 0;
		c = 0;
		scanf("%s",&n);
		if(n[0] == '-' && n[1] == '1')
			break;
		else if(n[0] == '0' && n[1] == '\0')
			continue;
		for(i=7;i>=0;i--){
			x=getnum(n[i]);
			y=test(i);
			num=num+x*y;
		}
		sum=0;
		while(num != 0){
			sum=sum+giveback(num);
			num=num-1;
		}
		for(i=10;i>=0;i--){
			k=sum % 2;
			if(k == 0)
				out[i][j] = '0';
			else
				out[i][j] = '1';
			sum = sum / 2;
		}
		j=j+1;
	}while(1);
	for(i=0;i<j;i++){
		for(k=0;k<11;k++)
			printf("%c",out[k][i]);
		printf("\n");
	}
	return 0;
}

