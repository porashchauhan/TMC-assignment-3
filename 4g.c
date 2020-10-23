#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node* left, *right;
};
 
int a[100];
int i = 0;
 
/*creates a new node */
 
struct node* createnode(int key)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
 
    return(newnode);
}
 
/* counts the number of nodes in a tree */
 
int count(struct node *n)
{
    int c = 1;
 
    if (n == NULL)
        return 0;
    else
    {
        c += count(n->left);
        c += count(n->right);
        return c;
    }
}
 
/*
 * Copies the nodes of Binary Tree in an array
 */
void binarytoarray(struct node * root, int a[], int *ptr)
{
    if(root != NULL)
    {
    binarytoarray(root->left, a, ptr);
    a[*ptr] = root->data;
    (*ptr)++;
    binarytoarray(root->right, a, ptr);
    }
}
 
/*
 * Copies the element of array to bst
 */
void arraytobst(int *arr, struct node *root, int *index)
{
    if(root != NULL)
    {
        arraytobst(arr, root->left, index);
        root->data = arr[i++];
        arraytobst(arr, root->right, index);
    }
}
 
int compare(const void *a, const void *b)
{
    return *(int*)a-*(int*)b;
}
 
/*
 * Inorder traversal of a tree
 */
 
void inorder(struct node *root)
{
    if(root !=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
 
/*
 * Converts binary tree to bst
 */
void binary_to_bst(struct node *root)
{
    int n, i;
 
    if (root == NULL)
        return;
    n = count(root);
    i = 0;
    binarytoarray(root, a, &i);
    qsort(&a, n, sizeof(a[0]), compare);
    i = 0;
    arraytobst(a, root, &i);
}
 
/*
 * Main Function
 */
 
int main()
{
    int flag = 0;
   
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
  
    struct node *newnode = createnode(numberArray[3]);
    newnode->left = createnode(numberArray[1]);
    newnode->right = createnode(numberArray[4]);
    newnode->left->left = createnode(numberArray[0]);
    newnode->left->right = createnode(numberArray[2]);
    printf("Inorder traversal of Input Binary Tree is\n");
    inorder(newnode);
    binary_to_bst(newnode);
    printf("\nInorder traversal of the converted Binary Search Tree is\n");
    inorder(newnode);
    return 0;
}