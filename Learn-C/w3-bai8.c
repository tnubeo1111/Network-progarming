#include <stdio.h>
struct student
{
    char name[50], CLASS[50];
    int birth;
};
int main()
{
    struct student s;
    
 printf("Enter The Information of Students :\n\n");
    
 printf("Enter Name : ");
    scanf("%s",s.name);
    
 printf("Enter Birth No. : ");
    scanf("%d",&s.birth);
    
    printf("Enter Class : ");
    scanf("%s",&s.CLASS);
    
    printf("\nDisplaying Information\n");
    
 printf("Name: %s\n",s.name);
    printf("Roll: %d\n",s.birth);
    printf("Marks: %s\n",s.CLASS);
    return 0;
}
