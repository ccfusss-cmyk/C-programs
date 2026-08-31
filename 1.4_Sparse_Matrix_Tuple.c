#include <stdio.h>
int main()
{
    int m[3][3];
    int tuple[10][3];
    int i,j,r,c,k=1;
    tuple[0][0]=3;
    tuple[0][1]=3;
    tuple[0][2]=0;
    printf("enter the elements of the matrix");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&m[i][j]);
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(m[i][j]!=0)
            {
                tuple[k][0]=i;
                tuple[k][1]=j;
                tuple[k][2]=m[i][j];
                k++;
            }
        }
    }
    tuple[0][2]=k-1;
    printf("tuple representation\n");
    printf("row\tcol\tvalue\n");
    for(i=0;i<k;i++)
    {
        printf("%d\t%d\t%d\n",tuple[i][0],tuple[i][1],tuple[i][2]);
    }
    return 0;
}
