#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
     int data; 
     struct node* left; 
     struct node* right; 
}; 
  

struct node* newNode(int data) 
{ 
     struct node* node = (struct node*)malloc(sizeof(struct node)); 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 
  
     return(node); 
} 
  
void printPreorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
     printf("%d ", node->data);   
     printPreorder(node->left);   
     printPreorder(node->right); 
}     
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
    struct node *root  = newNode(numberArray[3]); 
     root->left             = newNode(numberArray[1]); 
     root->right           = newNode(numberArray[4]); 
     root->left->left     = newNode(numberArray[0]); 
     root->left->right   = newNode(numberArray[2]);  
     printf("\nPreorder traversal of binary tree is \n"); 
     printPreorder(root); 
}