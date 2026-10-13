#include <stdio.h>
void printArray(int arr[], int n)
{
for (int i=0; i<n; i++)
printf("%d ", arr[i]);
printf("\n");
}
void readArray(int arr[], int n)
{
for (int i=0; i<n; i++)
scanf("%d", &arr[i]);
}
void insertionSort(int arr[], int n)
{
int i,j,key;
for(i = 1; i < n; i++)
{
key = arr[i];
j = i - 1;
while(j >= 0 && arr[j] > key)
{
arr[j + 1] = arr[j];
j--;
}
arr[j + 1] = key;
printArray(arr, n);
}
}
int main()
{
int arr[50] ;
int n;
printf("Enter the number of elements \n");
scanf("%d",&n);
printf("Enter the array elements\n");
readArray(arr,n);
printf("Original array: ");
printArray(arr, n);
insertionSort(arr, n);
printf("Sorted array: ");
printArray(arr, n);
return 0;
}
