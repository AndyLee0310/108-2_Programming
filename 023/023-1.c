#include <stdio.h>
#include <stdlib.h>

void test(int* x, int* y)
{
    int z = *x;
    *x = *y;
    *y = z;
}

void ptest(int w[], int ind, int ws,int **d,int *m)
{
    int i = 0,j = 0,t=0;

    if(ind == ws)
    {
        for(i = 0; i < ws-1; i++)
        {
            t+=d[w[i]-1][w[i+1]-1];
        }
        if(*m>t)
            *m=t;
    }
    else
    {
        for(j = ind;j < ws; j++)
        {
            test(&w[j],&w[ind]);
            ptest(w,ind+1,ws,d,m);
            test(&w[j],&w[ind]);
        }
    }
}

int main(){
    int r=0,i,j,n;
    scanf("%d",&n);
    int **d;
    d  = (int **)malloc(n *sizeof(int *));
    for(i=0;i<n;i++) 
        d[i] = (int *)malloc(n *sizeof(int));
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            scanf("%d",&d[i][j]);
            r +=d[i][j];
            }
        }
    int x[n];
    for(i=0;i<n;i++)
        x[i]=i+1;
    ptest(x,1,n,d,&r);
    printf ("%d",r);
    for(i=0;i<n;i++) 
        free(d[i]);
	
    return 0;
}