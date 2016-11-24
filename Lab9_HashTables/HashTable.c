#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "HashTable.h"


/// ====
/// Defines
/// ====


/// ====
/// Prototypes
/// ====


/// ====
/// Structures
/// ====
struct HashTable
{

};


/// ====
/// Constructors and Destructor
/// ====
HashTable *binarySearchTree_Constructor()
{
	HashTable *hashTable;
	hashTable = malloc(sizeof(HashTable));


	return hashTable;
}

void binarySearchTree_Deconstructor(HashTable *hashTable)
{

	free(hashTable);
}


/// ====
/// Public Functions
/// ====



/// ====
/// Helper Functions
/// ====

