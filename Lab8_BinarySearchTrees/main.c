//#define NDEBUG
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BinarySearchTree.h"


/// ====
/// Defines
/// ====
#define TEST_SIZE 32

/// ====
/// Prototypes
/// ====


/// ====
/// Main
/// ====
int main(void)
{
	srand((unsigned int)time(NULL));

	BinarySearchTree* tree = binarySearchTree_Constructor(TEST_SIZE/2);

	for (int i = 0; i < TEST_SIZE; i++)
	{
		insert(tree, rand() % TEST_SIZE);
	}

	binarySearchTree_Traverse(tree);

	printf("\n\n");

	binarySearchTree_Display(tree);

	printf("\n\nmax: %d \t min: %d \n", binarySearchTree_Max(tree), binarySearchTree_Min(tree));


	printf("PRESS KEY TO CONTINUE \n");
	getchar();

	binarySearchTree_Remove(tree, 5);

	binarySearchTree_Traverse(tree);

	printf("\n\n");

	binarySearchTree_Display(tree);

	printf("\n\nmax: %d \t min: %d \n", binarySearchTree_Max(tree), binarySearchTree_Min(tree));

	printf("PRESS KEY TO EXIT \n");
	getchar();
	return 0;
}

/// ====
/// Functions
/// ====