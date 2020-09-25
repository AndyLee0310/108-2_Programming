#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double getPoints(char *x){
    switch (*x){
        case 'A':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'J':
            return 0.5;
        case 'Q':
            return 0.5;
        case 'K':
            return 0.5;
        default:
            return 10;
    }
}

int main(){
	float userPoint=0,cpterPoint=0;
	char a[2];
	char b[2];
	int flagA=1,flagB=1;
	char wish[]="Y";
	scanf("%s",&a);
	userPoint=getPoints(a);
	scanf("%s",&b);
	cpterPoint=getPoints(b);
	while(flagA==1 || flagB==1){
		if(10.5>=userPoint && flagA == 1 && strcmp(wish,"Y") == 0){
			scanf("%s",&wish);
			if(strcmp(wish,"Y") == 0){
				scanf("%s",&a);
				userPoint+=getPoints(a);
				if(userPoint>10.5){
					userPoint=0;
					flagA=0;
				}
			}
		}else
            flagA=0;
		if((cpterPoint<=8.0 || cpterPoint<userPoint) && flagB == 1 && cpterPoint <=10.5){
			scanf("%s",&b);
			cpterPoint+=getPoints(b);
			if(cpterPoint>10.5){
				cpterPoint=0;
				flagB=0;
			}
		}else
            flagB=0;
}
    printf("%.1f vs. %.1f\n",userPoint,cpterPoint);
 	if(userPoint>cpterPoint)
 		printf("player wins");
 	else if(userPoint<cpterPoint)
 		printf("computer wins");
 	else
        printf("It's a tie");

	return 0;
}
