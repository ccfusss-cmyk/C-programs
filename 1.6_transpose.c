#include <stdio.h>

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

    for (int i = 1; i <= nonZero; i++)
    {
        scanf("%d%d%d", &s[i][0], &s[i][1], &s[i][2]);
    }

    t[0][0] = cols;
    t[0][1] = rows;
    t[0][2] = nonZero;

    for (int i = 1; i <= nonZero; i++)
    {
        t[i][0] = s[i][1];
        t[i][1] = s[i][0];
        t[i][2] = s[i][2];
    }

    printf("\nTranspose Sparse Matrix\n");
    printf("Row Col Val\n");

    for (int i = 0; i <= nonZero; i++)
    {
        printf("%d %d %d\n", t[i][0], t[i][1], t[i][2]);
    }
}

int main()
{
    int choice;

    printf("1. Transpose\n");
    printf("2. Addition\n");
    printf("3. Exit\n");

    while (1)
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                transpose();
                break;

            case 2:
                printf("Addition is implemented in the separate addition program.\n");
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
