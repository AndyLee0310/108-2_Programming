#include<stdio.h>
int getnum(int a){
	int m=(a+1)%9;
	switch(m){
		case 0:
			return 9;
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		case 4:
			return 4;
		case 5:
			return 5;
		case 6:
			return 6;
		case 7:
			return 7;
		case 8:
			return 8;
	}
}
int main(){
	int i,j,k,y;
    char informations[45]={0};
    char player[9][2];
    int x[9]={0};
    for(i=0;i<9;++i){
        scanf(" %d",&x[i]);
        for(j=0;j<x[i];++j){
            char c1,c2;
            scanf(" %c%c",&c1,&c2);
            if(c2=='O'){
                informations[j*9+i]='O';
            }else{
                informations[j*9+i]=c1;
            }
        }
    }
    for(i=0;i<9;i++){
	player[i][0]=0;
	player[i][1]=0;
	}

    int b[3]={0};
    int z=0,o=0,s=0,n=0;
    scanf(" %d",&z);
    scanf(" %d",&y);
    while(z>0){
        if(informations[n]=='O'){
            o+=1;
            if(o%3==0){
                o=0;
                b[0]=0;
                b[1]=0;
                b[2]=0;
            }
            z-=1;
        }else{
            if(informations[n]=='H'){
            	player[(n)%9][0]+=1;
                for(k=0;k<3;k++){
                    if(b[k]){
                    	player[b[k]][1]+=1;
                        s+=1;
                        b[k]=0;
                    }
                }
                s+=1;
            }else if(informations[n]=='1'){
                player[(n)%9][0]+=1;
                if(b[2]){s+=1;player[b[2]-1][1]+=1;}
                b[2]=b[1];
                b[1]=b[0];
                b[0]=getnum(n);
            }else if(informations[n]=='2'){
            	player[(n)%9][0]+=1;
                if(b[2] ){s+=1;player[b[2]-1][1]+=1;}
                if(b[1] ){s+=1;player[b[1]-1][1]+=1;}
                b[2]=b[0];
                b[0]=0;
                b[1]=getnum(n);
            }else if(informations[n]=='3'){
            	player[(n)%9][0]+=1;
                if(b[2]){
                    s+=1;
                    player[b[2]-1][1]+=1;
                }
                if(b[1]){
                    s+=1;
                    player[b[1]-1][1]+=1;
                }
                if(b[0]){
                    s+=1;
                    player[b[0]-1][1]+=1;
                }
                b[1]=0;
                b[0]=0;
                b[2]=getnum(n);
            }
        }
        n+=1;
    }
    printf("%d\n",s);
    printf("%d,%d\n",player[y-1][0],player[y-1][1]);

    return 0;
}
