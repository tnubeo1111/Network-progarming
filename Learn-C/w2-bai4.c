#include<stdio.h>
int main(){
    int i, n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements to be entered : ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    //Call a function Find maximum element of array
    int maxElementPos = findMaxElement(arr,n);
    printf("\nThe maximum element : %d", arr[maxElementPos]);
    //Call a function Find minimum element of array
    int minElementPos = findMinElement(arr,n);
    printf("\nThe minimum element : %d", arr[minElementPos]);
    //Call a function swap maximum and minimum element
    swapMaxMinElement(arr, maxElementPos, minElementPos);
    // Finally print array after swap
    printf("\nThe array after swap is : ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
//Find maximum element of array
int findMaxElement(int arr[],int n){
    int i, pos=0;
    int maxVal = arr[0];
    for(i=0;i<n;i++){
        if(arr[i]>maxVal){
            maxVal = arr[i];
            pos=i;
        }
    }
    return pos;
}
//Find minimum element of array
int findMinElement(int arr[],int n){
    int i, pos=0;
    int minVal = arr[0];
    for(i=0;i<n;i++){
        if(arr[i] < minVal){
            minVal = arr[i];
            pos=i;
        }
    }
    return pos;
}
//Swap maximum and minimum element
void swapMaxMinElement(int arr[], int maxElementPos, int minElementPos){
    int temp;
    temp = arr[maxElementPos];
    arr[maxElementPos] = arr[minElementPos];
    arr[minElementPos] = temp;
}
