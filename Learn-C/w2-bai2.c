#include <stdio.h>

int sum(int arr[], int n)
{
    int sum = 0; // initialize sum

    // Iterate through all elements
    // and add them to sum
    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}




int main()
{
    int arr[1000],i,n;  
 
     printf("Enter size of array: ");
    scanf("%d",&n);
 
     printf("Enter %d elements in the array : ", n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
 
    printf("\nElements in array are: ");
    for(i=0;i<n;i++)
 
    {
        printf("%d  ", arr[i]);
    }
 	
    n = sizeof(arr) / sizeof(arr[0]);
    printf("Sum of given array is %d", sum(arr, n));
    return 0;
}

