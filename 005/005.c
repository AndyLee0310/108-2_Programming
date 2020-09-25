#include <stdio.h>

/*將紙牌值對應到的點數回傳至main*/
double getpoint(int point){     //定義此函數必須要用double或float，不然換算到J、Q、K時就會出錯

    switch (point)
    {
        case 'A':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'J':
            return 0.5;
        case 'Q':
            return 0.5;
        case 'K':
            return 0.5;
        default:
            return 10;
    }
}

int main(){
    int i,j;
    double a=0,b=0;     //若用來計算點數的變數不為double或float的話，則不能輸出小數
    char aa[6],bb[6];

    /*A玩家的三張紙牌輸入(aa)&紙牌換算點數(a)*/
    for (i=0;i<3;i++){
        scanf(" %2c",&aa[i]);
        a+=getpoint(aa[i]);
    }

    /*B玩家的三張紙牌輸入(bb)&紙牌換算點數(b)*/
    for (j=0;j<3;j++){
        scanf(" %2c",&bb[j]);
        b+=getpoint(bb[j]);
    }

    /*若a的點數超過10.5即歸零，b亦同*/
    if (a>10.5)
        a=0;
    if (b>10.5)
        b=0;

    printf("%.1f\n",a);
    printf("%.1f\n",b);

    if (a>b)
        printf("A wins.");
    else if (a<b)
        printf("B wins.");
    else
        printf("It's a tie.");
}
