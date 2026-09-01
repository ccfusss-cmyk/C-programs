#include <stdio.h>

void sum();
void transpose();

int main()
{
    int c;
    printf("1. Transpose\n2. Addition\n3. Exit\n");

    while(1)
    {
        printf("\nEnter choice: ");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                transpose();
                break;

            case 2:
                sum();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

void transpose()
{
    int s[5][3], t[5][3];
    int rows, cols, nonZero;

    printf("Enter rows, columns and number of non-zero elements: ");
    scanf("%d%d%d", &rows, &cols, &nonZero);

    s[0][0] = rows;
    s[0][1] = cols;
    s[0][2] = nonZero;

    printf("Enter row column value:\n");

    for(int i = 1; i <= nonZero; i++)
    {
        scanf("%d%d%d", &s[i][0], &s[i][1], &s[i][2]);
    }

    t[0][0] = cols;
    t[0][1] = rows;
    t[0][2] = nonZero;

    for(int i = 1; i <= nonZero; i++)
    {
        t[i][0] = s[i][1];
        t[i][1] = s[i][0];
        t[i][2] = s[i][2];
    }

    printf("\nTranspose Sparse Matrix\n");
    printf("Row Col Val\n");

    for(int i = 0; i <= nonZero; i++)
    {
        printf("%d %d %d\n", t[i][0], t[i][1], t[i][2]);
    }
}

void sum()
{
    int a[5][3], b[5][3], c[5][3];
    int i = 1, j = 1, k = 1;

    printf("Enter rows, columns and non-zero elements of first matrix: ");
    scanf("%d%d%d", &a[0][0], &a[0][1], &a[0][2]);

    printf("Enter row column value:\n");

    for(i = 1; i <= a[0][2]; i++)
    {
        scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
    }

    printf("Enter rows, columns and non-zero elements of second matrix: ");
    scanf("%d%d%d", &b[0][0], &b[0][1], &b[0][2]);

    printf("Enter row column value:\n");

    for(i = 1; i <= b[0][2]; i++)
    {
        scanf("%d%d%d", &b[i][0], &b[i][1], &b[i][2]);
    }

    if(a[0][0] != b[0][0] || a[0][1] != b[0][1])
    {
        printf("Matrix addition not possible\n");
        return;
    }

    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    i = j = k = 1;

    while(i <= a[0][2] && j <= b[0][2])
    {
        if(a[i][0] == b[j][0] && a[i][1] == b[j][1])
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2] + b[j][2];

            i++;
            j++;
            k++;
        }
        else if(a[i][0] < b[j][0] ||
               (a[i][0] == b[j][0] && a[i][1] < b[j][1]))
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];

            i++;
            k++;
        }
        else
        {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];

            j++;
            k++;
        }
    }

    while(i <= a[0][2])
    {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];

        i++;
        k++;
    }

    while(j <= b[0][2])
    {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];

        j++;
        k++;
    }

    c[0][2] = k - 1;

    printf("\nSum of Sparse Matrices\n");
    printf("Row Col Val\n");

    for(i = 0; i <= c[0][2]; i++)
    {
        printf("%d %d %d\n", c[i][0], c[i][1], c[i][2]);
    }
}
