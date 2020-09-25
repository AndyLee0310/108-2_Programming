#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct people{
    int name;
    float fraction;
}people_t;

int main(){
    char *G[]={"A+","A","A-","B+","B","B-","C+","C","C-","F"},*p[10];
    char *GPA[]={"4.3","4.0","3.7","3.3","3.0","2.7","2.3","2.0","1.7","0"};
    char *S[]={"90-100","85-89","80-84","77-79","73-76","70-72","67-69","63-66","60-62","59¥H¤U"};
    float fraction[10]={95.0,87.0,82.0,78.0,75.0,70.0,68.0,65.0,60.0,50.0};
    int class_M,students_N,i,j,k,index=0,max=0,x;
	
    scanf(" %d",&class_M);
    
	char *FractionType[class_M][10];
    for(i=0;i<class_M;i++){
		scanf(" %s",FractionType+i);
	}
    scanf(" %d",&students_N);
    people_t stu[students_N];
    for(i=0;i<students_N;i++){
        scanf(" %d",&stu[i].name);
        stu[i].fraction = 0;
    
		for(j=0;j<class_M;j++){
            scanf(" %s",p);
			
			if(strcmp(FractionType+j,"G")==0){
                for(k=0;k<10;k++){
                    if(strcmp(p,*(G+k))==0)
						index = k;
                }
            }
            if(strcmp(FractionType+j,"GPA")==0){
                for(k=0;k<10;k++){
                    if(strcmp(p,*(GPA+k))==0)
						index = k;
                }
            }
            if(strcmp(FractionType+j,"S")==0){
                for(k=0;k<10;k++){
                    if(strcmp(p,*(S+k))==0)
						index = k;
                }
            }
            stu[i].fraction += fraction[index];
        }
    }
    for(i=0;i<3;i++){
        max = 0;
		
        for(j=0;j<students_N;j++){
            if(max<stu[j].fraction){
                max=stu[j].fraction;
                index = j;
            }
        }
        x = round((stu[index].fraction)/class_M);
        printf("%d\n",stu[index].name);
        printf("%d\n",x);
        stu[index].fraction = 0;
    }
	
    return 0;
}
