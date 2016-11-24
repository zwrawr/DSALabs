//#define NDEBUG
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "HashTable.h"


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

	HashTable *table = hashTable_Constructor();


	hashTable_Deconstructor(table);
	printf("PRESS KEY TO EXIT \n");
	getchar();
	return 0;
}

/// ====
/// Functions
/// ====