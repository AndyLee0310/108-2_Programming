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
    //�O��������T
    char hit_information[45]={0};
    char player[9][2];
    int a[9]={0};
    for(i=0;i<9;++i)
    {
        scanf(" %d",&a[i]);
        for(j=0;j<a[i];++j)
        {
            //Ū��������T����Ӧr���A�p�G�ĤG�Ӧr�OO�h��ܥX��
            char c1,c2;
            scanf(" %c%c",&c1,&c2);
            if(c2=='O')
            {
                //�X���h�O����'O'
                hit_information[j*9+i]='O';
            }
            else
            {
                //�w���h�O���Ĥ@�Ӧr��(1,2,3,H)
                hit_information[j*9+i]=c1;
            }
        }
    }
    //��l�Ʀ����w���Ƹ���� 
    for(i=0;i<9;i++) {
	player[i][0]=0;
	player[i][1]=0;
	}

    int base[3]={0};//�O���S�]�O�_���H
    int b=0,out=0,score=0,now=0;
    scanf(" %d",&b);
    scanf(" %d",&f);
    //�P�_�X���H��
    //b��ܤW�ݭn�h�֤H�X���Anow���Ū����ĴX����T�Aout�P�_�O�_�T�X��
    while(b>0)
    {
        //�p�G���X��
        if(hit_information[now]=='O')
        {
            out+=1;//�X��

            //�p�G�T�X���A�M���S�]
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
            //�p�G�O���S��
            if(hit_information[now]=='H')
            {
            	player[(now)%9][0]+=1;
                for(k=0;k<3;k++)
                {
                    //�S�W�C���@�H�[�@���A�òM���S�]
                    if(base[k])
                    {
                    	player[base[k]][1]+=1;
                        score+=1;
                        base[k]=0;
                    }
                }
                //�����̥[�@��
                score+=1;
            }
            //�@�S��
            else if(hit_information[now]=='1')
            {
                //�p�G�T�S���H�[�@���A�åB�C�@�S�����@�S
                player[(now)%9][0]+=1; 
                if(base[2]){score+=1;player[base[2]-1][1]+=1;}
                base[2]=base[1];
                base[1]=base[0];
                base[0]=getNum(now);
            }
            //�G�S��
            else if(hit_information[now]=='2')
            {
            	player[(now)%9][0]+=1;
                //�p�G�@�G�S���H�[�@��
                if(base[2] ){score+=1;player[base[2]-1][1]+=1;}
                if(base[1] ){score+=1;player[base[1]-1][1]+=1;}
                //�@�S�H������T�S
                base[2]=base[0];
                base[0]=0;
                //������W�G�S
                base[1]=getNum(now);
            }
            //�T�S��
            else if(hit_information[now]=='3')
            {
            	player[(now)%9][0]+=1;
                //�@�G�T�S�W���H�[��
                if(base[2] ){score+=1;player[base[2]-1][1]+=1;}
                if(base[1] ){score+=1;player[base[1]-1][1]+=1;}
                if(base[0] ){score+=1;player[base[0]-1][1]+=1;}
                base[1]=0;
                base[0]=0;
                //������W�T�S
                base[2]=getNum(now);
            }
        }
        now+=1;
    }
    printf("%d\n",score);
    printf("%d,%d\n",player[f-1][0],player[f-1][1]);

    return 0;
}
