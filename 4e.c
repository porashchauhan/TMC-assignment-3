#include<stdio.h> 
#include<stdlib.h> 
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
   
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  
/* Prototypes of a utility function to get the maximum 
   value in inorder[start..end] */
int max(int inorder[], int strt, int end); 
  
/* A utility function to allocate memory for a node */
struct node* newNode(int data); 
  
/* Recursive function to construct binary of size len from 
   Inorder traversal inorder[]. Initial values of start and end 
   should be 0 and len -1.  */
struct node* buildTree (int inorder[], int start, int end) 
{ 
    if (start > end) 
        return NULL; 
  
    /* Find index of the maximum element from Binary Tree */
    int i = max (inorder, start, end); 
  
    /* Pick the maximum value and make it root */
    struct node *root = newNode(inorder[i]); 
  
    /* If this is the only element in inorder[start..end], 
       then return it */
    if (start == end) 
        return root; 
  
    /* Using index in Inorder traversal, construct left and 
       right subtress */
    root->left  = buildTree (inorder, start, i-1); 
    root->right = buildTree (inorder, i+1, end); 
  
    return root; 
} 
  
/* UTILITY FUNCTIONS */
/* Function to find index of the maximum value in arr[start...end] */
int max (int arr[], int strt, int end) 
{ 
    int i, max = arr[strt], maxind = strt; 
    for(i = strt+1; i <= end; i++) 
    { 
        if(arr[i] > max) 
        { 
            max = arr[i]; 
            maxind = i; 
        } 
    } 
    return maxind; 
} 
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node* newNode (int data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return node; 
} 

 
/*
 * Function to ascertain the height of a Tree
 */
 
int heightoftree(struct node* root)
{
    int max;
 
    if (root!=NULL)
    {
        /*Finding the height of left subtree.*/
        int leftsubtree = heightoftree(root->left); 
 
        /*Finding the height of right subtree.*/
        int rightsubtree = heightoftree(root->right); 
 
        if (leftsubtree > rightsubtree)
        {
            max = leftsubtree + 1;
            return max;
        }
        else
        {
            max = rightsubtree + 1;
            return max;
        }
    }
}
 
/*
 * Function to print all the nodes left to right of the current level
 */
 
void left_to_right(struct node* root, int level)
{
    if (root != NULL)
    {
        if (level == 1)
        {
            printf("%d ", root->data);
        }
 
        else if (level > 1)
        {
            left_to_right(root->left, level-1);
            left_to_right(root->right, level-1);
        }
    }
}
 
void right_to_left(struct node *root, int level)
{
    if(root!=NULL)
    {
        if(level==1)
        {
            printf("%d ", root->data);
        }
        else
        {
            right_to_left(root->right, level-1);
            right_to_left(root->left, level-1);
        }
    }
} 

/* This funtcion is here just to test buildTree() */
void printInorder (struct node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder (node->left); 
  
    /* then print the data of node */
    printf("%d ", node->data); 
  
    /* now recur on right child */
    printInorder (node->right); 
} 
void printPreorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
     printf("%d ", node->data);   
     printPreorder(node->left);   
     printPreorder(node->right); 
}   

void printPostorder(struct node* node) 
{ 
     if (node == NULL) 
        return; 
  
     // first recur on left subtree 
     printPostorder(node->left); 
  
     // then recur on right subtree 
     printPostorder(node->right); 
  
     // now deal with the node 
     printf("%d ", node->data); 
} 
  

int main() 
{ 
   
    int flag = 0;
    int j;
    int num;
    
    printf("enter the number of nodes\n");
    scanf("%d", &num);
    int inorder[num];
    printf("enter the inorder traversal\n");
    for(j=0;j<num;j++)
    {
        scanf("%d", &inorder[j]);
        
    }
    
    int len = sizeof(inorder)/sizeof(inorder[0]); 
    struct node *root = buildTree(inorder, 0, len - 1); 
  
    /* Let us test the built tree by printing Insorder traversal */
    int exit=0;
    int option;
    while(exit!=1)
    {
        printf("select an option\n");
        printf("1. preorder\n");
        printf("2. postorder\n");
        printf("3. inorder\n");
        printf("4. zigzag\n");
        printf("5. exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
             printf("\n Preorder traversal of the constructed tree is \n"); 
             printPreorder(root);
             printf("\n");
            break;
        case 2:
            printf("\n Postorder traversal of the constructed tree is \n"); 
   
            printPostorder(root);
             printf("\n");
            break;
        case 3:
            printf("\n Inorder traversal of the constructed tree is \n"); 
           printInorder(root); 
            printf("\n");
           break;

        case 4:
           printf("\n zigzag traversal is \n");
    int i;
    int height = heightoftree(root);
    for(i = 1; i <= height; i++)
    {
        if(i%2 != 0)
        {   
            flag = 0;
            left_to_right(root,i);
        }
 
        if(i%2 == 0)
        {
            flag = 1;
            right_to_left(root,i);
        }
    }
     printf("\n");
      break;
      case 5:
      exit=1;
      break;
       
        }
    }
  
    return 0; 
} 