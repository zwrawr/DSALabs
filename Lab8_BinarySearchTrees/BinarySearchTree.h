#ifndef BinarySearchTree_H_INCLUDED
#define BinarySearchTree_H_INCLUDED

/// ====
/// TypeDefs
/// ====
typedef struct BinarySearchTree BinarySearchTree;


/// ====
/// Constructors and Destructor
/// ====
BinarySearchTree *binarySearchTree_Constructor(int value);
void binarySearchTree_Deconstructor(BinarySearchTree *binarySearchTree);


/// ====
/// Functions
/// ====
void binarySearchTree_Insert(BinarySearchTree *binarySearchTree, int value);
void binarySearchTree_Display(BinarySearchTree *binarySearchTree);
void binarySearchTree_Traverse(BinarySearchTree *binarySearchTree);
int binarySearchTree_Search(BinarySearchTree *binarySearchTree, int value);
int binarySearchTree_Max(BinarySearchTree *binarySearchTree);
int binarySearchTree_Min(BinarySearchTree *binarySearchTree);
void binarySearchTree_Remove(BinarySearchTree *binarySearchTree,int value);



#endif // BinarySearchTree_H_INCLUDED