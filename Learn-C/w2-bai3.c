#include <stdio.h>
 
// Function to find maximum in arr[] of size n
int largest(int arr[], int n)
{
    int i;
 
    // Initialize maximum element
    int max = arr[0];
 
    // Traverse array elements from second and
    // compare every element with current max
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
 
    return max;
}
 
// Driver code
int main()
{
    int arr[100],n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter %d elenments in the arr: ",n);
    for(int i = 0; i<n; i++)
    {
    	scanf("%d",&arr[i]);
    }
    n = sizeof(arr) / sizeof(arr[0]);
   
    // Function call
    printf("Largest in given array is %d", largest(arr, n));
    return 0;
}
