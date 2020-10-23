#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node* left, *right;
};
 
 
struct node* createnode(int key)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;
 
    return(newnode);
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
            printf("%d ", root->info);
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
            printf("%d ", root->info);
        }
        else
        {
            right_to_left(root->right, level-1);
            right_to_left(root->left, level-1);
        }
    }
}
 
int main()
{
    int flag = 0;
    struct node *newnode = createnode(1);
    newnode->left = createnode(2);
    newnode->right = createnode(3);
    newnode->left->left = createnode(4);
    newnode->left->right = createnode(5);
    
 
    
 
    printf("Spiral Traversal of Tree 1 is \n");
 
    int i;
    int height = heightoftree(newnode);
    for(i = 1; i <= height; i++)
    {
        if(i%2 != 0)
        {   
            flag = 0;
            left_to_right(newnode,i);
        }
 
        if(i%2 == 0)
        {
            flag = 1;
            right_to_left(newnode,i);
        }
    }
}
