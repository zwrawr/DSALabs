#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

/// ====
/// Defines
/// ====
#define HASH_MAX_ALPHABETIC_UPPER_CASE 630
#define HASH_MAX_ALPHABETIC_LOWER_CASE 854
#define HASH_MAX_ASCII 889



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



#endif // HASHTABLE_H_INCLUDED