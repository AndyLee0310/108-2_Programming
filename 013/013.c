#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	int count,i,m,j=0,k,x,y;
	char n[8];
	char out[32][5];
	do{
		m= 0;
		count = 0;
		scanf("%s",&n);
		if(n[0] == '-' && n[1] == '1')
			break;
		else if(n[0] == '0' && n[1] == '\0')
			continue;
		for(i=7;i>=0;i--){
			x=getnum(n[i]);
			y=test(i);
			m=m+x*y;
		}
		while(m != 1){
			if(m == 0){
				count=0;
				break;
			}
			if(m % 2 == 0){
				m=m/2;
				count=count+1;
			}
			else{
				m=(m+1)/2;
				count=count+1;
			}
		}
		for(i=3;i>=0;i--){
			k=count % 2;
			if(k == 0)
				out[j][i] = '0';
			else
				out[j][i] = '1';
			count = count / 2;
		}
		j=j+1;
	}while(1);
	for(i=0;i<j;i++){
		for(k=0;k<4;k++)
			printf("%c",out[i][k]);
		printf("\n");
	}
	return 0;
}

