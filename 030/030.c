#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test(int *arr_word1,int *arr_word2,int word1_len,int word2_len){
    int a;
    if(word1_len<word2_len)   return -1;
    else if(word1_len>word2_len)  return 1;
    else if(word1_len==word2_len){
        for(a=0;a<300;a++){
            if(*(arr_word1+a)<*(arr_word2+a)){
                return -1;
            }
        }
        for(a=0;a<300;a++){
            if(*(arr_word1+a)>*(arr_word2+a)){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int i,j,word1_len,word2_len,c=0,o[300],A_arr[300],B_arr[300],f=0,x=0;
    char All_arr[300],s1='+',s2='+',op;
	
    for(i=0;i<300;i++)  
		All_arr[i]='\0';
    for(i=0;i<300;i++)  
		A_arr[i]=0;
    for(i=0;i<300;i++)  
		B_arr[i]=0;
    for(i=0;i<300;i++)  
		o[i]=0;
    
	scanf(" %c",&op);
    scanf(" %s",All_arr);
    
	if(strcmp(All_arr,"0")==0)  x=1;
    word1_len = strlen(All_arr);
	
    for(i=0;i<word1_len;i++){
        if(All_arr[i]!='-')  
			A_arr[300-word1_len+i] = All_arr[i]-48;
    }
    if(All_arr[0]=='-'){
        s1 = '-';
        word1_len--;
    }
    for(i=0;i<300;i++)  All_arr[i]='\0';
    scanf(" %s",All_arr);
    if(strcmp(All_arr,"0")==0)  x=1;
    word2_len = strlen(All_arr);
    for(i=0;i<word2_len;i++){
        if(All_arr[i]!='-')  
			B_arr[300-word2_len+i] = All_arr[i]-48;
    }
    if(All_arr[0]=='-'){
        s2 = '-';
        word2_len--;
    }
    if(op=='1'){
        if(s1=='+'&&s2=='+'){
            for(i=299;i>=0;i--){
                o[i] = A_arr[i]+B_arr[i]+c;
                c = o[i]/10;
                o[i] %= 10;
            }
        }else if(s1=='+'&&s2=='-'){
            if(test(&A_arr[0],&B_arr[0],word1_len,word2_len)==-1){
                printf("-");
                for(i=299;i>=0;i--){
                    if(B_arr[i]<A_arr[i]){
                        o[i] = 10-A_arr[i]+B_arr[i];
                        B_arr[i-1]--;
                    }else  
						o[i] = B_arr[i]-A_arr[i];
                }
            }else{
                for(i=299;i>=0;i--){
                    if(A_arr[i]<B_arr[i]){
                        o[i] = 10-B_arr[i]+A_arr[i];
                        A_arr[i-1]--;
                    }else
						o[i] = A_arr[i]-B_arr[i];
                }
            }
        }else if(s1=='-'&&s2=='+'){
            if(test(&A_arr[0],&B_arr[0],word1_len,word2_len)==-1){
                for(i=299;i>=0;i--){
                    if(B_arr[i]<A_arr[i]){
                        o[i] = 10-A_arr[i]+B_arr[i];
                        B_arr[i-1]--;
                    }else
						o[i] = B_arr[i]-A_arr[i];
                }
            }else if(test(&A_arr[0],&B_arr[0],word1_len,word2_len)==0){}
            else{
                printf("-");
                for(i=299;i>=0;i--){
                    if(A_arr[i]<B_arr[i]){
                        o[i] = 10-B_arr[i]+A_arr[i];
                        A_arr[i-1]--;
                    }else
						o[i] = A_arr[i]-B_arr[i];
                }
            }
        }else{
            printf("-");
            for(i=299;i>=0;i--){
                o[i] = A_arr[i]+B_arr[i]+c;
                c = o[i]/10;
                o[i] %= 10;
            }
        }
    }
    else if(op=='2'){
        if(s1=='+'&&s2=='+'){
            if(test(&A_arr[0],&B_arr[0],word1_len,word2_len)==-1){
                printf("-");
                for(i=299;i>=0;i--){
                    if(B_arr[i]<A_arr[i]){
                        o[i] = 10-A_arr[i]+B_arr[i];
                        B_arr[i-1]--;
                    }else
						o[i] = B_arr[i]-A_arr[i];
                }
            }else{
                for(i=299;i>=0;i--){
                    if(A_arr[i]<B_arr[i]){
                        o[i] = 10-B_arr[i]+A_arr[i];
                        A_arr[i-1]--;
                    }else
						o[i] = A_arr[i]-B_arr[i];
                }
            }
        }
        else if(s1=='+'&&s2=='-'){
            for(i=299;i>=0;i--){
                o[i] = A_arr[i]+B_arr[i]+c;
                c = o[i]/10;
                o[i] %= 10;
            }
        }
        else if(s1=='-'&&s2=='+'){
            printf("-");
            for(i=299;i>=0;i--){
                o[i] = A_arr[i]+B_arr[i]+c;
                c = o[i]/10;
                o[i] %= 10;
            }
        }
        else{
            if(test(&A_arr[0],&B_arr[0],word1_len,word2_len)==-1){
                for(i=299;i>=0;i--){
                    if(B_arr[i]<A_arr[i]){
                        o[i] = 10-A_arr[i]+B_arr[i];
                        B_arr[i-1]--;
                    }else
						o[i] = B_arr[i]-A_arr[i];
                }
            }
            else if(test(&A_arr[0],&B_arr[0],word1_len,word2_len)==0){}
            else{
                printf("-");
                for(i=299;i>=0;i--){
                    if(A_arr[i]<B_arr[i]){
                        o[i] = 10-B_arr[i]+A_arr[i];
                        A_arr[i-1]--;
                    }else
						o[i] = A_arr[i]-B_arr[i];
                }
            }
        }
    }
    else{
        if(((s1=='-'&&s2=='+')||(s1=='+'&&s2=='-'))&&x==0){
            printf("-");
            for(i=299;i>=149;i--){
                for(j=299;j>=149;j--){
                    o[i+j-299] += c+A_arr[j]*B_arr[i];
                    c = o[i+j-299]/10;
                    o[i+j-299] %= 10;
                }
            }
        }else{
            for(i=299;i>=149;i--){
                for(j=299;j>=149;j--){
                    o[i+j-299] += c+A_arr[j]*B_arr[i];
                    c = o[i+j-299]/10;
                    o[i+j-299] %= 10;
                }
            }
        }
    }
    for(i=0;i<300;i++){
        if(o[i]!=0||f==1){
            printf("%d",o[i]);
            f = 1;
        }
    }
    if(f==0)
		printf("%d",0);
    
	return 0;
}
