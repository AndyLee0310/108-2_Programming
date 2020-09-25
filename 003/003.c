#include <stdio.h>

int main()
{
    int hr1, hr2, x, y;
    float a, b, c;
    scanf("%d",&hr1);
    scanf("%d",&hr2);
    scanf("%d",&x);
    scanf("%d",&y);
    a=((hr1+hr2)*x)*0.08;   //稅金
    b=y*0.05;   //勞保費
    c=((hr1+hr2)*x)-a-b;    //實際所得
    printf("%.1f\n",c);
    printf("%.1f\n",b);
    printf("%.1f",a);

    return 0;
}
