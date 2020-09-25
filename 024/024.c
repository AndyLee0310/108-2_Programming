#include <stdio.h>
#include <string.h>

int main(){
	int i=0,j=0,o;
 	char w1[100000],w2[100000],w3[100000],w4[100000],x[10000],y[10000],r[1000][1000];
  	char *d= " ",t[100000];
	char *p,*p2,*p3;
	int f[100000],tp=0;

	gets(w1);
	gets(x);
	gets(y);

	memset(t,'\0',100000);

	for(i=0;i<100000;i++){
		f[i]=0;
		w2[i]=w1[i];
		w3[i]=w1[i];
		w4[i]=w1[i];
	}

	p= strtok(w1,d);
	i=0;

	while (p!= NULL){
		j=0;
		while(*(p+j)!='\0'){
			r[i][j] = *(p+j);
			j++;
		}

		if(*p==*x && strcmp(p,x)==0){
			printf("%s ",y);
		}else{
		    printf("%s ",p);
        }
		p= strtok(NULL,d);
		i++;
	}
	o=i;

	printf("\n");
	p2= strtok(w3,d);
	while (p2!= NULL){
		if(*p2==*x && strcmp(p2,x)==0){
			printf("%s %s ",y,p2);
		}
		else
			printf("%s ",p2);
		p2= strtok(NULL,d);
	}
	printf("\n");
	p3= strtok(w4,d);
	while (p3!= NULL){
		if(*p3==*x && strcmp(p3,x)==0){
			printf("");
		}
		else
			printf("%s ",p3);
		p3= strtok(NULL,d);
	}
	printf("\n");
	for(i=0;i<o;i++) f[i]=1;
	for(i=0;i<o;i++){
		for(j=i;j<o;j++){
			if(!(strcmp(r[i],r[j]))&& i!=j && f[i]!=0){
				f[i]++;
				f[j]=0;
			}
		}
	}

	for(i=0;i<o;i++){
		for(j=0;j<o-1;j++){
			if(strcmp(r[j],r[j+1])>0){
				strcpy(t,r[j]);
				strcpy(r[j],r[j+1]);
				strcpy(r[j+1],t);
				tp=f[j];
				f[j]=f[j+1];
				f[j+1]=tp;
            }
		}
	}

	for(i=0;i<o;i++){
		for(j=0;j<o-1;j++){
			if(f[j]<f[j+1]){
				strcpy(t,r[j]);
				strcpy(r[j],r[j+1]);
				strcpy(r[j+1],t);
				tp=f[j];
				f[j]=f[j+1];
				f[j+1]=tp;
			}
		}
	}

	for(i=0;i<o;i++){
		if(f[i]>0){
			printf("%s : %d\n",r[i],f[i]);
		}
	}

	return 0;
}
