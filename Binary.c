#include <stdio.h>
int main()
{
int arr[100], n, i, item;
int beg, end, mid;
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter %d sorted elements:\n", n);
for(i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}
printf("Enter the element to search: ");
scanf("%d", &item);
beg = 0;
end = n - 1;
mid = (beg + end) / 2;
while((beg <= end) && (arr[mid]!=item))
{
if(arr[mid] < item)
beg = mid + 1;
else
end = mid - 1;
mid = (beg+end)/2;
}
if(arr[mid] == item)
printf("Element %d found at position %d.\n", item, mid + 1);
else
printf("Element %d not found in the array.\n", item);
return 0;
}
