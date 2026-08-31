#include <stdio.h>

int main()
{
    int arr[100];
    int key;
    int n, i;
    int low = 0, high, mid;

    printf("number of elements");
    scanf("%d", &n);

    printf("enter the elements");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("enter the element to be searched");
    scanf("%d", &key);

    high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            printf("element %d found out position%d", key, mid + 1);
            return 0;
        }
        else if(arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("element not found");
    return 0;
}
