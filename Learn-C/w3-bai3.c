#include <stdio.h>
   
int main()
{
   
    // Get the two Strings to be concatenated
    char str1[100], str2[100], str3[100];
   
    printf("Nhap chuoi 1: ");
    scanf("%s",&str1);

    printf("Nhap chuoi 2:");
    scanf("%s",&str2);
   
    int i = 0, j = 0;
   
   
    // Insert the first string
    // in the new string
    while (str1[i] != '\0') {
        str3[j] = str1[i];
        i++;
        j++;
    }
   
    // Insert the second string
    // in the new string
    i = 0;
    while (str2[i] != '\0') {
        str3[j] = str2[i];
        i++;
        j++;
    }
    str3[j] = '\0';
   
    printf("\nConcatenated string: %s", str3);
   
    return 0;
}
