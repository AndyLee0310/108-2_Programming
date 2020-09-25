#include <stdio.h>
#include <stdlib.h>
#define len(x) sizeof(x) / sizeof(x[0])

int Data[5][9]={{0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0}};

int conf[3]={0,0,0};

int main(){
    int course_N,hr,i,j,course;
    for(i=0;i<3;i++){
        scanf("%d",&course_N);
        scanf("%d",&hr);
        for(j=0;j<hr;j++){
            scanf("%d",&course);
            if(Data[course/10-1][course%10-1] != 0){
                conf[0]=Data[course/10-1][course%10-1];
                conf[1]=course_N;
                conf[2]=course;
            }
            Data[course/10-1][course%10-1]=course_N;
            fflush(stdin);
        }
        fflush(stdin);
    }
    printf("%d and %d conflict on %d",conf[0],conf[1],conf[2]);
}
