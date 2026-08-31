#include <stdio.h>
int main()
{
    int p[3],q[3],r[3];
    int i;
    printf("enter the coeff of the first polynomial");
    for(i=0;i<3;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("enter the coeff of the second polynomial");
    for(i=0;i<3;i++)
    {
        scanf("%d",&q[i]);
    }
    for(i=0;i<3;i++)
    {
        r[i]=p[i]+q[i];
    }
    printf("the polynomial");
    printf("%d X^2+%dX+%d\n",r[0],r[1],r[2]);
    return 0;
}
