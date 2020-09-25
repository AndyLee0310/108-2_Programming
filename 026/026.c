#include <stdio.h>
#include <string.h>
#include <ctype.h>

int testmax(int a,int b) {
    if(a >= b)
        return a;
    else
        return b;
}

char test(char x)
{
    if(islower(x)) return 'l';
    if(isupper(x)) return 'u';
    return 'n';
}

int main(void) {
    char w[100000];
    int g;
    scanf("%d",&g);
        int m=0;
        int nm=0;
        scanf("%s", w);
        int l=strlen(w);

        char pl='n';
        char cl;
        int ck=0;

        if(g == 1){
            for(int i = 0; i < l; i++){
                cl = test(w[i]);
                if(pl != cl)
                    nm++;
                else
                    nm = 1;

                m = testmax(nm, m);
                pl = cl;
            }
        }else{
            for(int i = 0; i < l; i++){
                cl = test(w[i]);
                if(pl == cl){
                    ck++;
                    if(ck == g){
                        nm += g;
                        m = testmax(nm, m);
                    }
                    if(ck > g)
                        nm = g;
                }else if(pl != cl){
                    if(ck < g) nm = 0;
                    ck = 1;
                }
                pl = cl;
            }
        }
        printf("%d\n", m);
		
    return 0;
}
