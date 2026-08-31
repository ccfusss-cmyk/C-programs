#include <stdio.h>
int main()
{
    int arr[100];
    int key;
    int i,n,found=0;
    printf("number of elements");
    scanf("%d",&n);
    printf("enter the elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the element to be searched");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if (arr[i]==key)
        {
            found=1;
            printf("number %d found at position %d",key,i+1);
            break;
        }
    }
    if (found==0)
    {
        printf("element not found%d",key);
    }
    return 0;
}
