#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

/// ====
/// Defines
/// ====
<<<<<<< HEAD
#define HASH_TABLE_DEFAULT_SIZE 1000
=======
#define HASH_MAX_ALPHABETIC_UPPER_CASE 631
#define HASH_MAX_ALPHABETIC_LOWER_CASE 855
#define HASH_MAX_ASCII 890
>>>>>>> 06897a9b5222c0865995e92eaf2e1a93779f7240



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


#endif // HASHTABLE_H_INCLUDED