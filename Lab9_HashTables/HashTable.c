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
int hash(char *key, int numBuckets);


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
void hashTable_Insert(struct HashTable *hashTable, char *key, char *value)
{
    int hashValue = hash(key, hashTable->numBuckets);
    
    HashElement *element = hashElement_Constructor(key, value);
    
    if (hashTable->buckets[0] == NULL)
    {
        hashTable->buckets[hashValue] = element;
    }
    else
    {
        HashElement *curr = hashTable->buckets[hashValue];
        
        
        int i = 0;
        
        do
        {
            curr = curr->next;
            i++;
        }
        while (curr->next != NULL);
        
        curr->next = element;
    }
    
    hashTable->numElements++;
    free(element);
}


/// ====
/// Helper Functions
/// ====
int hash(char *key, int numBuckets)
{
    return  key[0] + 2 * key[1] + 4 * key[2] % numBuckets;
}

