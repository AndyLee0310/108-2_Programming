#include <stdio.h>

/*以183型的費率來計算費用*/
double money183(int a,int b,int c,int d,int e){
    double sum;
    sum=a*0.08+b*0.1393+c*0.1349+d*1.1287+e*1.4803;
    if(sum<183)
        return 183;
    else
        return sum;
}

/*以383型的費率來計算費用*/
double money383(int a,int b,int c,int d,int e){
    double sum;
    sum=a*0.07+b*0.1304+c*0.1217+d*1.1127+e*1.2458;
    if(sum<383)
        return 383;
    else
        return sum;
}

/*以983型的費率來計算該月費用*/
double money983(int a,int b,int c,int d,int e){
    double sum;
    sum=a*0.06+b*0.1087+c*0.1018+d*0.9572+e*1.1243;
    if(sum<983)
        return 983;
    else
        return sum;
}


int main(){
    int a,b,c,d,e;
    double sum183,sum383,sum983;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    scanf("%d",&d);
    scanf("%d",&e);

    /*先取得各類型的費用*/
    sum183=money183(a,b,c,d,e);
    sum383=money383(a,b,c,d,e);
    sum983=money983(a,b,c,d,e);

    /*再來比較何種類型的資費為最佳資費*/
    if(sum183<sum383&&sum183<sum983)
        printf("183");
    else if(sum383<sum183&&sum383<sum983)
        printf("383");
    else if(sum983<sum183&&sum983<sum383)
        printf("983");
}
