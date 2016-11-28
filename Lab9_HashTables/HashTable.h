#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

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



#endif // HASHTABLE_H_INCLUDED