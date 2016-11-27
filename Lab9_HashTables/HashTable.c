#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "HashTable.h"


/// ====
/// Defines
/// ====
#define MAX_KEY_LENGTH 4
#define MAX_VALUE_LENGTH 128


/// ====
/// TypeDefs
/// ====
typedef struct HashElement HashElement;

/// ====
/// Prototypes
/// ====
HashElement *hashElement_Constructor(char *key, char *value);
void hashElement_Deconstructor(HashElement *hashElement);


/// ====
/// Structures
/// ====
struct HashTable
{
    int numBuckets;
    int numElements;
    HashElement **buckets;
};


struct HashElement
{
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    HashElement *next;
};


/// ====
/// Constructors and Destructor
/// ====
HashElement *hashElement_Constructor(char *key, char *value)
{
    HashElement *hashElement;
    hashElement = malloc(sizeof(HashElement));
    
    
    strcpy_s(hashElement->key, MAX_KEY_LENGTH, key);
    strcpy_s(hashElement->value, MAX_VALUE_LENGTH, value);
    hashElement->next = NULL;
    
    return hashElement;
}

void hashElement_Deconstructor(HashElement *hashElement)
{
    if (hashElement->next != NULL)
    {
        hashElement_Deconstructor(hashElement->next);
    }
    
    free(hashElement);
    return;
}

HashTable *hashTable_Constructor(int numBuckets)
{
    HashTable *hashTable;
    hashTable = malloc(sizeof(HashTable));
    
    hashTable->numBuckets = numBuckets;
    
    hashTable->buckets = malloc(numBuckets * sizeof(HashElement));
    
    for (int i = 0; i < numBuckets; i++)
    {
        hashTable->buckets[i] = NULL;
    }
    
    hashTable->numElements = 0;
    
    return hashTable;
}

void hashTable_Deconstructor(HashTable *hashTable)
{

    for (int i = 0; i < hashTable->numBuckets; i++)
    {
        if (hashTable->buckets[i] != NULL)
        {
            hashElement_Deconstructor(hashTable->buckets[i]);
        }
    }
    
    free(hashTable);
}


/// ====
/// Public Functions
/// ====



/// ====
/// Helper Functions
/// ====

