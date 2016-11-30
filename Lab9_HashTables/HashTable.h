#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

/// ====
/// Defines
/// ====
#define HASH_TABLE_DEFAULT_SIZE 1000

/// ====
/// TypeDefs
/// ====
typedef struct HashTable HashTable;


/// ====
/// Constructors and Destructor
/// ====
HashTable *hashTable_Constructor(int numBuckets);
void hashTable_Deconstructor(HashTable *hashTable);


/// ====
/// Functions
/// ====
void hashTable_Insert(HashTable *hashTable, char *key, char *value);
void hashTable_Display(struct HashTable *hashTable);
char *hashTable_Search(HashTable *hashTable, char *key);
float hashTable_GetLoadFactor(HashTable *hashTable);


#endif // HASHTABLE_H_INCLUDED