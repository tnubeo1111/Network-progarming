#include<stdio.h>
 
// Funtion removing spaces from string
char * removeSpacesFromStr(char *string)
{
    // non_space_count to keep the frequency of non space characters
    int non_space_count = 0;
 
    //Traverse a string and if it is non space character then, place it at index non_space_count
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != ' ')
        {
            string[non_space_count] = string[i];
            non_space_count++;//non_space_count incremented
        }    
    }
    
    //Finally placing final character at the string end
    string[non_space_count] = '\0';
    return string;
}
 
int main()
{
    char string[100];
    printf("Input String: ")
    scanf("%s",&string)
    printf("%s \n",string);
    printf("%s",removeSpacesFromStr(string));
    return 0;
}
