#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double function1(double x,double y){return sqrt(x-y*y);}
double function2(double x,double y){return (x*y*y*y+7*y)/(sqrt(x+y));}
double function_abs(double y){
    if(y<0)  return -y;
    else  return y;
}

int main(){
    int m=0,index;
    double x,p,q,err,Area1=0,Area2=0,j;
    char op;
    scanf(" %c",&op);
    while(op!='0'){
        m = 0;
        scanf(" %lf",&x);
        scanf(" %lf",&p);
        scanf(" %lf",&q);
        scanf(" %lf",&err);
        if(op=='1'){
            do{
                Area1=Area2=0;
                index = 1;
                for(j=0;j<m;j++)  index*=2;
                for(j=p+(q-p)/index;j<q;j=j+(q-p)/index){
                    Area1 += function_abs(2*function_abs(function1(x,j)));
                }
                index *= 2;
                for(j=p+(q-p)/index;j<q;j=j+(q-p)/index){
                    Area2 += function_abs(2*function_abs(function1(x,j)));
                }
                Area1 = function_abs((function_abs(function1(x,p))+function_abs(function1(x,q))+Area1)*((q-p)/(index/2))/2);
                Area2 = function_abs((function_abs(function1(x,p))+function_abs(function1(x,q))+Area2)*((q-p)/index/2));
                m++;
            }while(function_abs((Area2-Area1))>pow(10,-err));
        }
        else{
            do{
                Area1=Area2=0;
                index = 1;
                for(j=0;j<m;j++)  index*=2;
                for(j=p+(q-p)/index;j<q;j=j+(q-p)/index){
                    Area1 += function_abs(2*function_abs(function2(x,j)));
                }
                index *= 2;
                for(j=p+(q-p)/index;j<q;j=j+(q-p)/index){
                    Area2 += function_abs(2*function_abs(function2(x,j)));
                }
                Area1 = function_abs((function_abs(function2(x,p))+function_abs(function2(x,q))+Area1)*((q-p)/(index/2))/2);
                Area2 = function_abs((function_abs(function2(x,p))+function_abs(function2(x,q))+Area2)*((q-p)/index/2));
                m++;
            }while(function_abs((Area2-Area1))>pow(10,-err));
        }
        printf("%.12f\n",Area2);
        scanf(" %c",&op);
    }
    return 0;
}
