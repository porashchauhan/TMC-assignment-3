#include <stdio.h>
int main()
{

    FILE *myFile;
    myFile = fopen("somenumbers.txt", "r");

    //read file into array
    int n;
    printf("enter the number of elements in the input file\n");
    scanf("%d", &n);
    int numberArray[n];
    int i;

    for (i = 0; i < n; i++)
    {
        fscanf(myFile, "%d", &numberArray[i]);
    }
   printf("Your inorder traversal is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", numberArray[i]);
    }


}