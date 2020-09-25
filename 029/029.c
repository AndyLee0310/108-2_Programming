#include <stdio.h>
#include <string.h>

typedef struct llDub_s{
    int intp[100];
    int intpleg;
    int floatp[100];
    int floatpleg;
    int signal;
}llDub_t;
int add(int x[],int y[],int out[],int al,int bl){
    int c=0,lo=0;
    int otemp[300];
    while(al>=0 || bl>=0){
        al--;
        bl--;
        int A;
        int B;
        if(al <0)
            A=0;
        else
            A=x[al];
        if(bl<0)
            B=0;
        else
            B=y[bl];
        int sum=A+B+c;
        otemp[lo]=sum%10;
        c = sum/10;
        lo++;
    }
    for(int index=0;index<lo;index++)
        out[index]=otemp[index];
    upsidedown(out,lo);
    return lo;
}
int floatAdd(int x[],int y[],int out[],int al,int bl){
    int c=0,lo=0;
    int otemp[300];
    if(al>bl){
        for(int i=bl;i<al;i++){
            y[i]=0;
        }
        bl=al;
    }else if(bl>al){
        for(int i=al;i<bl;i++){
            x[i]=0;
        }
        al=bl;
    }
    al--;
    while(al>=0){
        int A;
        int B;
        A=x[al];
        B=y[al];
        int sum=A+B+c;
        otemp[lo]=sum%10;
        c = sum/10;
        lo++;
        al--;
    }
    otemp[lo]=c;
    lo++;
    for(int index=0;index<lo;index++)
        out[index]=otemp[index];
    upsidedown(out,lo);
    return lo;
}
int sub(int x[],int y[],int out[],int al,int bl){
    int borr=0,lo=0,pb=0;
    int otemp[200];
    al--;
    bl--;
    while(al>=0 || bl>=0){
        pb=borr;
        int A;
        int B;
        if(al <0)
            A=0;
        else
            A=x[al];
        if(bl<0)
            B=0;
        else
            B=y[bl];
        if(A-pb<B){
            borr=1;
            A+=10;
        }else{
            borr=0;
        }
        int sum=A-B-pb;
        otemp[lo]=sum%10;
        lo++;
        al--;
        bl--;
    }
    for(int index=0;index<lo;index++)
        out[index]=otemp[index];
    upsidedown(out,lo);
    return lo;
}
int floatSub(int x[],int y[],int out[],int al,int bl){
    int borr=0,lo=0,pb=0;
    int otemp[200];
    if(al>bl){
        for(int i=bl;i<al;i++){
            y[i]=0;
        }
        bl=al;
    }else if(bl>al){
        for(int i=al;i<bl;i++){
            x[i]=0;
        }
        al=bl;
    }
    al--;
    while(al>=0){
        pb=borr;
        int A;
        int B;
        A=x[al];
        B=y[al];
        if(A-pb<B){
            borr=1;
            A+=10;
        }else{
            borr=0;
        }
        int sum=A-B-pb;
        otemp[lo]=sum%10;
        lo++;
        al--;
    }
    for(int index=0;index<lo;index++)
        out[index]=otemp[index];
    upsidedown(out,lo);
    return lo;
}
int multDigit(int x[],int y,int out[],int al,int offset){
    int c=0,lo=0,off;
    while(al>=0){
        al--;
        int A;
        if(al <0)
            A=0;
        else
            A=x[al];
        int sum=A*y+c;
       // printf("sum: %d ",sum);
        out[lo]=sum%10;
        c = sum/10;
        lo++;
    }
    //printf("\n");
    upsidedown(out,lo);
    for(off=0;off<offset;off++){
        out[lo]=0;
        lo++;
    }
    return lo;
}
int multi(int x[],int y[],int out[],int al,int bl){
    int total[500]={0};
    int lo,lto=1;
    upsidedown(y,bl);
    for(int i=0;i<bl;i++){
        lo=multDigit(x,y[i],out,al,i);
        lto=add(total,out,total,lto,lo);
    }
    for(int index=0;index<lto;index++)
        out[index]=total[index];
    return lto;
}
void upsidedown(int inp[],int length){
    int tmp[500];
    int index;
    for(index=length-1;index>=0;index--){
        tmp[length-index-1]=inp[index];
    }
    for(index=0;index<length;index++){
        inp[index]=tmp[index];
    }
}
int isBigger(int x[],int y[],int al,int bl){
    if(al>bl)
        return 1;
    else if(al<bl)
        return -1;
    else{
        for(int i=0;i<al;i++){
            if(x[i]>y[i])
                return 1;
            else if(x[i]<y[i])
                return -1;
        }
        return 0;
    }
}
int isFloatBigger(int x[],int y[],int al,int bl){
    int l;
    if(al>bl)
        l=bl;
    else
        l=al;
    for(int i=0;i<l;i++){
        if(x[i]>y[i])
            return 1;
        else if(x[i]<y[i])
            return -1;
    }
    if(al>bl)
        return 1;
    else if(al<bl)
        return -1;
    return 0;

}
void print(int o[],int length,int haveMinus,int maxPrintLength,int isFloat){
    int zero=1;
    int plength;
    if(length>maxPrintLength)
        plength=maxPrintLength;
    else
        plength=length;
    if(haveMinus)
        printf("-");
    if(!isFloat){
        for(int i=0;i<plength;i++){
            if(o[i]==0 && zero)
                continue;
            else
                zero=0;
            printf("%d",o[i]);
        }
        if(zero)
            printf("0");
    }else{
        int test0=1;
        for(int j=0;j<plength;j++){
            if(o[j]!=0){
                test0=0;
                break;
            }
        }
        if(test0)
            return;
        printf(".");
        for(int i=0;i<plength;i++){
            test0=1;
            for(int j=i;j<plength;j++){
                if(o[j]!=0){
                    test0=0;
                    break;
                }
            }
            if(test0)
                break;
            printf("%d",o[i]);
        }
    }
}
void AddDO(llDub_t out,llDub_t x,llDub_t y,int printFotleng){
    out.intpleg=add(x.intp,y.intp,out.intp,x.intpleg,y.intpleg);
    out.floatpleg=floatAdd(x.floatp,y.floatp,out.floatp,x.floatpleg,y.floatpleg);
    int *pint=out.floatp;
    int cmpL;
    if(x.floatpleg>y.floatpleg)
        cmpL=x.floatpleg;
    else
        cmpL=y.floatpleg;
    if(out.floatpleg>cmpL){
        int temp[10];
        int tempL=out.floatpleg-cmpL;
        for(int i=0;i<tempL;i++){
            temp[i]=out.floatp[i];
        }
        pint+=tempL;
        out.intpleg=add(out.intp,temp,out.intp,out.intpleg,tempL);
    }
    print(out.intp,out.intpleg,0,120,0);
    if(out.intpleg>120){
        printf("\n");
        return;
    }
    print(pint,cmpL,0,printFotleng,1);
    printf("\n");
}
void SubDO(llDub_t out,llDub_t x,llDub_t y,int printFotleng){
    int temp[1]={1};
    if(isBigger(x.intp,y.intp,x.intpleg,y.intpleg)>0){
        out.intpleg=sub(x.intp,y.intp,out.intp,x.intpleg,y.intpleg);
        if(isFloatBigger(x.floatp,y.floatp,x.floatpleg,y.floatpleg)>0){
            out.floatpleg=floatSub(x.floatp,y.floatp,out.floatp,x.floatpleg,y.floatpleg);
            print(out.intp,out.intpleg,0,120,0);
            if(out.intpleg>120){
                printf("\n");
                return;
            }
            print(out.floatp,out.floatpleg,0,printFotleng,1);
            printf("\n");
        }else if(isFloatBigger(x.floatp,y.floatp,x.floatpleg,y.floatpleg)<0){
            out.floatpleg=floatSub(x.floatp,y.floatp,out.floatp,x.floatpleg,y.floatpleg);
            out.intpleg=sub(out.intp,temp,out.intp,out.intpleg,1);
            print(out.intp,out.intpleg,0,120,0);
            if(out.intpleg>120){
                printf("\n");
                return;
            }
            print(out.floatp,out.floatpleg,0,printFotleng,1);
            printf("\n");
        }else{
            print(out.intp,out.intpleg,0,120,0);
            printf("\n");
        }
    }else if(isBigger(x.intp,y.intp,x.intpleg,y.intpleg)<0){
        out.intpleg=sub(y.intp,x.intp,out.intp,y.intpleg,x.intpleg);
        if(isFloatBigger(x.floatp,y.floatp,x.floatpleg,y.floatpleg)>0){
            out.floatpleg=floatSub(y.floatp,x.floatp,out.floatp,y.floatpleg,x.floatpleg);
            out.intpleg=sub(out.intp,temp,out.intp,out.intpleg,1);
            print(out.intp,out.intpleg,1,120,0);
            if(out.intpleg>120){
                printf("\n");
                return;
            }
            print(out.floatp,out.floatpleg,0,printFotleng,1);
            printf("\n");
        }else if(isFloatBigger(x.floatp,y.floatp,x.floatpleg,y.floatpleg)<0){
            out.floatpleg=floatSub(y.floatp,x.floatp,out.floatp,y.floatpleg,x.floatpleg);
            print(out.intp,out.intpleg,1,120,0);
            if(out.intpleg>120){
                printf("\n");
                return;
            }
            print(out.floatp,out.floatpleg,0,printFotleng,1);
            printf("\n");
        }else{
            print(out.intp,out.intpleg,1,120,0);
            printf("\n");
        }
    }else{
        if(isFloatBigger(x.floatp,y.floatp,x.floatpleg,y.floatpleg)>0){
            out.floatpleg=floatSub(x.floatp,y.floatp,out.floatp,x.floatpleg,y.floatpleg);
            printf("0");
            print(out.floatp,out.floatpleg,0,printFotleng,1);
            printf("\n");
        }else if(isFloatBigger(x.floatp,y.floatp,x.floatpleg,y.floatpleg)<0){
            out.floatpleg=floatSub(y.floatp,x.floatp,out.floatp,y.floatpleg,x.floatpleg);
            printf("-0");
            int test0=1;
            for(int j=0;j<printFotleng;j++){
                if(out.floatp[j]!=0){
                    test0=0;
                    break;
                }
            }
            if(test0){
                printf("\r0   \n");
                return;
            }
            print(out.floatp,out.floatpleg,0,printFotleng,1);
            printf("\n");
        }else
            printf("0\n");
    }
}
void MultDO(llDub_t out,llDub_t x,llDub_t y,int printFotleng,int combA[],int combineB[],int combAleg,int combineBLength){
    int multiOutput[500];
    int mulOpt;
    mulOpt= multi(combA,combineB,multiOutput,combAleg,combineBLength);
    int zero=1,count=0,floatLength=0;
    int isFloat=0;
    int floatAmount=y.floatpleg+x.floatpleg;
    upsidedown(combineB,combineBLength);
    int test0=1;
    for(int j=0;j<mulOpt;j++){
        if(multiOutput[j]!=0){
            test0=0;
            break;
        }
    }
    if(test0)
        printf("0\n");
    for(int i=0;i<mulOpt;i++){
        if(multiOutput[i]==0&&zero&&((mulOpt-i)>floatAmount))
            continue;
        zero=0;
        test0=1;
        for(int j=i;j<mulOpt;j++){
            if(multiOutput[j]!=0){
                test0=0;
                break;
            }
        }
        if((mulOpt-i)==floatAmount){
            if(test0)
                break;
            if(count==0){
                printf("0");
                count=1;
            }
            test0=1;
            for(int j=i;j<i+printFotleng;j++){
                if(multiOutput[j]!=0){
                    test0=0;
                    break;
                }
            }
            if(test0)
                break;
            printf(".");
            isFloat=1;
        }
        if(test0&&isFloat)
            break;
        printf("%d",multiOutput[i]);
        if(isFloat)
            floatLength++;
        count++;
        if(count==120||(floatLength==printFotleng &&printFotleng!=0)){
            break;
        }
    }
}
int main(){
    char fir[150];
    char sec[150];
    int printFotleng;
    scanf(" %s",fir);
    scanf(" %s",sec);
    scanf(" %d",&printFotleng);
    int al = strlen(fir);
    int bl = strlen(sec);
    llDub_t x;x.floatp[0]=0;x.floatpleg=1;
    llDub_t y;y.floatp[0]=0;y.floatpleg=1;
    llDub_t out;
    int isFloatPart=0;
    char *p=fir;
    if(fir[0]=='-'){
        x.signal=1;
        p++;
    }else
        x.signal=0;
    int index=0,findex=0;
    int combA[200];
    int combAleg=0;
    int combineB[200];
    int combineBLength=0;
    for(index=0,findex=0;index<al-x.signal;index++){
        if(p[index]=='.'){
            isFloatPart=1;
            continue;
        }
        combA[combAleg]=(p[index]-48);
        combAleg++;
        if(!isFloatPart)
            x.intp[index]=(p[index]-48);
        else{
            x.floatp[findex]=(p[index]-48);
            findex++;
        }
    }
    x.floatpleg=findex;
    x.intpleg=al-x.signal-findex-isFloatPart;
    p=sec;
    isFloatPart=0;
    if(sec[0]=='-'){
        y.signal=1;
        p++;
    }else
        y.signal=0;
    for(index=0,findex=0;index<bl-y.signal;index++){
        if(p[index]=='.'){
            isFloatPart=1;
            continue;
        }
        combineB[combineBLength]=(p[index]-48);
        combineBLength++;
        if(!isFloatPart)
            y.intp[index]=(p[index]-48);
        else{
            y.floatp[findex]=(p[index]-48);
            findex++;
        }
    }
    y.floatpleg=findex;
    y.intpleg=bl-y.signal-findex-isFloatPart;

    if(x.signal==0&&y.signal==0){
        AddDO(out,x,y,printFotleng);
        if(strcmp(fir,sec)==0)
            printf("0\n");
        else
            SubDO(out,x,y,printFotleng);
        MultDO(out,x,y,printFotleng,combA,combineB,combAleg,combineBLength);
    }else if(x.signal==0&&y.signal==1){
        if(strcmp(fir,sec)==0)
            printf("0\n");
        else
            SubDO(out,x,y,printFotleng);
        AddDO(out,x,y,printFotleng);
        printf("-");
        MultDO(out,x,y,printFotleng,combA,combineB,combAleg,combineBLength);
    }else if(x.signal==1&&y.signal==0){
        if(strcmp(fir,sec)==0)
            printf("0\n");
        else
            SubDO(out,y,x,printFotleng);
        printf("-");
        AddDO(out,x,y,printFotleng);
        printf("-");
        MultDO(out,x,y,printFotleng,combA,combineB,combAleg,combineBLength);
    }else if(x.signal==1&&y.signal==1){
        printf("-");
        AddDO(out,x,y,printFotleng);
        if(strcmp(fir,sec)==0)
            printf("0\n");
        else
            SubDO(out,y,x,printFotleng);
        MultDO(out,x,y,printFotleng,combA,combineB,combAleg,combineBLength);
    }
    return 0;
}
