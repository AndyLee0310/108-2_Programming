#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0, j = 0, x = 0, m = 0, a = 0, b, f = 0, ck = 0, t = 0;
    int w1t, w2t[100], r[100], w1_len[100], w2_len[100][100], dl[100][100], ds[100];
    char temp[400], w[100][100], wlist[100][100][100];
    scanf("%[^\n]", &temp);
	
    for(i = 0 ; i < strlen(temp) ; i++){
        if(temp[i] == ' '){
            r[j] = i;
            j++;
        }
    }
	
    r[j++] = strlen(temp);
    j = 0;
	
    for(i = 0 ; i < strlen(temp) + 1 ; i++){
        if(r[j] == i){
            w1_len[j] = x;
            j++;
            x = 0;
            continue;
        }
        w[j][x] = temp[i];
        x++;
    }
    w1t = j;
    int checkSen[w1t];
	
    for(i = 0 ; i < w1t ; i++)
        checkSen[i] = 0;
  
    scanf(" %d",&b);
    while(m < b){
        j = 0;
        scanf(" %[^\n]", &temp);
        for(i = 0 ; i < strlen(temp) ; i++){
            if(temp[i] == ' '){
                r[j] = i;
                j++;
            }
        }
        r[j++] = strlen(temp);
        j = 0;
        for(i = 0 ; i < strlen(temp) + 1 ; i++){
            if(r[j] == i){
                w2_len[m][j] = x;
                j++;
                x = 0;
                continue;
            }
            wlist[m][j][x] = temp[i];
            x++;
        }
        w2t[m] = j;
        m++;
    }

    for(i = 0 ; i < b ; i++){
        a = -1;
        for(j = 0 ; j < w2t[i] ; j++){
            if(a > -1){
                for(m = 0 ; m < a + 1 ; m++){
                    if(dl[i][m] == j)
                        f = 1;
                }
                if(f == 1){
                    f = 0;
                    continue;
                }
            }
			
            for(x = 0 ; x < w2t[i] ; x++){
                if((j != x)&&(strcmp(wlist[i][j], wlist[i][x]) == 0)){
                    a++;
                    dl[i][a] = x;
                }
            }
        }
        ds[i] = a + 1;
    }
	
    for(m = 0 ; m < b ; m++){
        for(i = m + 1 ; i < b ; i++){
            ck = 0;
            x = 0;
			
            for(j = 0 ; j < w2t[m] ; j++){
                if((dl[m][0] > 0)&&(dl[m][x] == j)){
                    x++;
                    continue;
                }
				
                for(a = 0 ; a < w1t ; a++){
                    if(strcmp(w[a], wlist[m][j]) == 0)
                        checkSen[a] = 1;
                }
            }
            x = 0;
            for(j = 0 ; j < w2t[i] ; j++){
                if((dl[i][0] > 0)&&(dl[i][x] == j)){
                    x++;
                    continue;
                }
				
                for(a = 0 ; a < w1t ; a++){
                    if(strcmp(w[a], wlist[i][j]) == 0)
                        checkSen[a] = 1;
                }
            }
			
            for(j = 0 ; j < w1t ; j++)
                ck += checkSen[j];
            if(((w2t[i] + w2t[m] - ds[i] - ds[m]) == w1t)&&(ck == w1t))
                t++;
            for(j = 0 ; j < w1t ; j++)
                checkSen[j] = 0;
        }
    }
    printf("%d",t);
    return 0;
}
