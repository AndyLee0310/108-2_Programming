#include<stdio.h>
int getNum(int x){
	int j=(x+1)%9;
	switch(j){
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
int main()
{
	int i,j,k,f;
    //記錄打擊資訊
    char hit_information[45]={0};
    char player[9][2];
    int a[9]={0};
    for(i=0;i<9;++i)
    {
        scanf(" %d",&a[i]);
        for(j=0;j<a[i];++j)
        {
            //讀取打擊資訊的兩個字元，如果第二個字是O則表示出局
            char c1,c2;
            scanf(" %c%c",&c1,&c2);
            if(c2=='O')
            {
                //出局則記錄為'O'
                hit_information[j*9+i]='O';
            }
            else
            {
                //安打則記錄第一個字元(1,2,3,H)
                hit_information[j*9+i]=c1;
            }
        }
    }
    //初始化成員安打數跟分數 
    for(i=0;i<9;i++) {
	player[i][0]=0;
	player[i][1]=0;
	}

    int base[3]={0};//記錄壘包是否有人
    int b=0,out=0,score=0,now=0;
    scanf(" %d",&b);
    scanf(" %d",&f);
    //判斷出局人數
    //b表示上需要多少人出局，now表示讀取到第幾筆資訊，out判斷是否三出局
    while(b>0)
    {
        //如果為出局
        if(hit_information[now]=='O')
        {
            out+=1;//出局

            //如果三出局，清空壘包
            if(out%3==0)
            {
                out=0;
                base[0]=0;
                base[1]=0;
                base[2]=0;
            }
            b-=1;
        }
        else
        {
            //如果是全壘打
            if(hit_information[now]=='H')
            {
            	player[(now)%9][0]+=1;
                for(k=0;k<3;k++)
                {
                    //壘上每有一人加一分，並清空壘包
                    if(base[k])
                    {
                    	player[base[k]][1]+=1;
                        score+=1;
                        base[k]=0;
                    }
                }
                //打擊者加一分
                score+=1;
            }
            //一壘打
            else if(hit_information[now]=='1')
            {
                //如果三壘有人加一分，並且每一壘推移一壘
                player[(now)%9][0]+=1; 
                if(base[2]){score+=1;player[base[2]-1][1]+=1;}
                base[2]=base[1];
                base[1]=base[0];
                base[0]=getNum(now);
            }
            //二壘打
            else if(hit_information[now]=='2')
            {
            	player[(now)%9][0]+=1;
                //如果一二壘有人加一份
                if(base[2] ){score+=1;player[base[2]-1][1]+=1;}
                if(base[1] ){score+=1;player[base[1]-1][1]+=1;}
                //一壘人推移到三壘
                base[2]=base[0];
                base[0]=0;
                //打擊手上二壘
                base[1]=getNum(now);
            }
            //三壘打
            else if(hit_information[now]=='3')
            {
            	player[(now)%9][0]+=1;
                //一二三壘上有人加分
                if(base[2] ){score+=1;player[base[2]-1][1]+=1;}
                if(base[1] ){score+=1;player[base[1]-1][1]+=1;}
                if(base[0] ){score+=1;player[base[0]-1][1]+=1;}
                base[1]=0;
                base[0]=0;
                //打擊手上三壘
                base[2]=getNum(now);
            }
        }
        now+=1;
    }
    printf("%d\n",score);
    printf("%d,%d\n",player[f-1][0],player[f-1][1]);

    return 0;
}
