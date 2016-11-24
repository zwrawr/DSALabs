#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BinarySearchTree.h"


/// ====
/// Defines
/// ====
#define DISPLAYSTRINGSIZE 10000


/// ====
/// Prototypes
/// ====
char *displayRecurrent(BinarySearchTree *binarySearchTree, char *prefix, int isTail, char *result);
int height(BinarySearchTree *binarySearchTree);
BinarySearchTree *leftRotate(BinarySearchTree *binarySearchTree);
BinarySearchTree *rightRotate(BinarySearchTree *binarySearchTree);
int getBalance(BinarySearchTree *binarySearchTree);
int maxof(int a, int b);
BinarySearchTree *insert(BinarySearchTree *binarySearchTree, int value);
BinarySearchTree *minValueNode(BinarySearchTree *binarySearchTree);
BinarySearchTree *removeValue(BinarySearchTree *binarySearchTree, int value);


/// ====
/// Structures
/// ====
struct BinarySearchTree
{
    int value;
    BinarySearchTree *left;
    BinarySearchTree *right;
    int height;
};


/// ====
/// Constructors and Destructor
/// ====
BinarySearchTree *binarySearchTree_Constructor(int value)
{
    BinarySearchTree *binarySearchTree;
    binarySearchTree = malloc(sizeof(BinarySearchTree));
    
    binarySearchTree->value = value;
    binarySearchTree->left = NULL;
    binarySearchTree->right = NULL;
    binarySearchTree->height = 1;
    
    return binarySearchTree;
}

void binarySearchTree_Deconstructor(BinarySearchTree *binarySearchTree)
{
    if (binarySearchTree->left != NULL)
    {
        binarySearchTree_Deconstructor(binarySearchTree->left);
    }
    
    if (binarySearchTree->right != NULL)
    {
        binarySearchTree_Deconstructor(binarySearchTree->right);
    }
    
    free(binarySearchTree);
}


/// ====
/// Public Functions
/// ====
// from http://www.elec.york.ac.uk/internal_web/meng/yr2/modules/DSA/DSA/Labs/Scripts/Lab8-BinarySearchTree.pdf
void binarySearchTree_Display(BinarySearchTree *binarySearchTree)
{
    char result[DISPLAYSTRINGSIZE] = "";
    char prefix[1] = "";
    printf("%s", displayRecurrent(binarySearchTree, prefix, 1, result));
}

void binarySearchTree_Insert(BinarySearchTree *binarySearchTree, int value)
{
    binarySearchTree = insert(binarySearchTree, value);
    return;
}

void binarySearchTree_Traverse(BinarySearchTree *binarySearchTree)
{
    if (binarySearchTree != NULL)
    {
        binarySearchTree_Traverse(binarySearchTree->left);
        printf("%d, ", binarySearchTree->value);
        binarySearchTree_Traverse(binarySearchTree->right);
    }
}

int binarySearchTree_Search(BinarySearchTree *binarySearchTree, int value)
{
    if (binarySearchTree == NULL)
    {
        return 0;
    }
    else if (binarySearchTree->value == value)
    {
        return 1;
    }
    else if (value < binarySearchTree->value)
    {
        return binarySearchTree_Search(binarySearchTree->left, value);
    }
    else
    {
        return binarySearchTree_Search(binarySearchTree->right, value);
    }
}

int binarySearchTree_Max(BinarySearchTree *binarySearchTree)
{
    if (binarySearchTree->right == NULL)
    {
        return binarySearchTree->value;
    }
    else
    {
        return binarySearchTree_Max(binarySearchTree->right);
    }
}

int binarySearchTree_Min(BinarySearchTree *binarySearchTree)
{
    if (binarySearchTree->left == NULL)
    {
        return binarySearchTree->value;
    }
    else
    {
        return binarySearchTree_Min(binarySearchTree->left);
    }
}

void binarySearchTree_Remove(BinarySearchTree *binarySearchTree, int value)
{
    binarySearchTree = removeValue(binarySearchTree, value);
}

/// ====
/// Helper Functions
/// ====
// from http://www.elec.york.ac.uk/internal_web/meng/yr2/modules/DSA/DSA/Labs/Scripts/Lab8-BinarySearchTree.pdf
char *displayRecurrent(BinarySearchTree *binarySearchTree, char *prefix, int isTail, char *result)
{
    char string[DISPLAYSTRINGSIZE] = "";
    char value[128] = "";
    sprintf_s(value, 128, "%d", binarySearchTree->value);
    
    if (binarySearchTree->right != NULL)
    {
        string[0] = '\0';
        strcat_s(string, DISPLAYSTRINGSIZE, prefix);
        strcat_s(string, DISPLAYSTRINGSIZE, isTail ? "|   " : "    ");
        displayRecurrent(binarySearchTree->right, string, 0, result);
    }
    
    strcat_s(result, DISPLAYSTRINGSIZE, prefix);
    strcat_s(result, DISPLAYSTRINGSIZE, isTail ? " -- " : " -- ");
    strcat_s(result, DISPLAYSTRINGSIZE, value);
    strcat_s(result, DISPLAYSTRINGSIZE, "\n");
    
    if (binarySearchTree->left != NULL)
    {
        string[0] = '\0';
        strcat_s(string, DISPLAYSTRINGSIZE, prefix);
        strcat_s(string, DISPLAYSTRINGSIZE, isTail ? "    " : "|   ");
        displayRecurrent(binarySearchTree->left, string, 1, result);
    }
    
    return result;
}

int height(BinarySearchTree *binarySearchTree)
{
    if (binarySearchTree == NULL)
    {
        return 0;
    }
    else
    {
        return binarySearchTree->height;
    }
}

BinarySearchTree *rightRotate(BinarySearchTree *binarySearchTree)
{
    BinarySearchTree *leftSide = binarySearchTree->left;
    BinarySearchTree *temp = leftSide->right;
    
    leftSide->right = binarySearchTree;
    binarySearchTree->left = temp;
    
    binarySearchTree->height = maxof(
                                   height(binarySearchTree->left),
                                   height(binarySearchTree->right))
                               + 1;
    leftSide->height = maxof(
                           height(leftSide->left),
                           height(leftSide->right))
                       + 1;
                       
    return leftSide;
}

BinarySearchTree *leftRotate(BinarySearchTree *binarySearchTree)
{
    BinarySearchTree *rigthSide = binarySearchTree->right;
    BinarySearchTree *temp = rigthSide->left;
    
    rigthSide->left = binarySearchTree;
    binarySearchTree->right = temp;
    
    binarySearchTree->height = maxof(
                                   height(binarySearchTree->left),
                                   height(binarySearchTree->right))
                               + 1;
    rigthSide->height = maxof(
                            height(rigthSide->left),
                            height(rigthSide->right))
                        + 1;
                        
    return rigthSide;
}

int getBalance(BinarySearchTree *binarySearchTree)
{
    if (binarySearchTree == NULL)
    {
        return 0;
    }
    else
    {
        return height(binarySearchTree->left) - height(binarySearchTree->right);
    }
}

int maxof(int a, int b)
{
    return (a > b) ? a : b;
}

BinarySearchTree *insert(BinarySearchTree *binarySearchTree, int value)
{
    if (binarySearchTree == NULL)
    {
        return binarySearchTree_Constructor(value);
    }
    
    if (value < binarySearchTree->value)
    {
        binarySearchTree->left = insert(binarySearchTree->left, value);
    }
    else if (value > binarySearchTree->value)
    {
        binarySearchTree->right = insert(binarySearchTree->right, value);
    }
    else
    {
        return binarySearchTree;
    }
    
    binarySearchTree->height = 1 + maxof(height(binarySearchTree->left),
                                         height(binarySearchTree->right));
                                         
    int balance = getBalance(binarySearchTree);
    
    // Left Left Case
    if (balance > 1 && value < binarySearchTree->left->value)
    {
        return rightRotate(binarySearchTree);
    }
    
    // Right Right Case
    if (balance < -1 && value > binarySearchTree->right->value)
    {
        return leftRotate(binarySearchTree);
    }
    
    // Left Right Case
    if (balance > 1 && value > binarySearchTree->left->value)
    {
        binarySearchTree->left = leftRotate(binarySearchTree->left);
        return rightRotate(binarySearchTree);
    }
    
    // Right Left Case
    if (balance < -1 && value < binarySearchTree->right->value)
    {
        binarySearchTree->right = rightRotate(binarySearchTree->right);
        return leftRotate(binarySearchTree);
    }
    
    return binarySearchTree;
}

BinarySearchTree *removeValue(BinarySearchTree *binarySearchTree, int value)
{

    if (binarySearchTree == NULL)
    {
        return binarySearchTree;
    }
    
    if (value < binarySearchTree->value)
    {
        binarySearchTree->left = removeValue(binarySearchTree->left, value);
    }
    else if (value > binarySearchTree->value)
    {
        binarySearchTree->right = removeValue(binarySearchTree->right, value);
    }
    else
    {
        if ((binarySearchTree->left == NULL) || (binarySearchTree->right == NULL))
        {
            BinarySearchTree *temp = binarySearchTree->left ? binarySearchTree->left : binarySearchTree->right;
            
            if (temp == NULL)
            {
                temp = binarySearchTree;
                binarySearchTree = NULL;
            }
            else
            {
                *binarySearchTree = *temp;
            }
            
            free(temp);
        }
        else
        {
            BinarySearchTree *temp = minValueNode(binarySearchTree->right);
            
            binarySearchTree->value = temp->value;
            
            binarySearchTree->right = removeValue(binarySearchTree->right, temp->value);
        }
    }
    
    if (binarySearchTree == NULL)
    {
        return binarySearchTree;
    }
    
    binarySearchTree->height = 1 + maxof(height(binarySearchTree->left), height(binarySearchTree->right));
    
    int balance = getBalance(binarySearchTree);
    
    if (balance > 1 && getBalance(binarySearchTree->left) >= 0)
    {
        return rightRotate(binarySearchTree);
    }
    
    if (balance > 1 && getBalance(binarySearchTree->left) < 0)
    {
        binarySearchTree->left = leftRotate(binarySearchTree->left);
        return rightRotate(binarySearchTree);
    }
    
    if (balance < -1 && getBalance(binarySearchTree->right) <= 0)
    {
        return leftRotate(binarySearchTree);
    }
    
    if (balance < -1 && getBalance(binarySearchTree->right) > 0)
    {
        binarySearchTree->right = rightRotate(binarySearchTree->right);
        return leftRotate(binarySearchTree);
    }
    
    return binarySearchTree;
}

BinarySearchTree *minValueNode(BinarySearchTree *binarySearchTree)
{
    BinarySearchTree *curr = binarySearchTree;
    
    while (curr->left != NULL)
    {
        curr = curr->left;
    }
    
    return curr;
}
