#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


/// ====
/// TypeDefs
/// ====
typedef struct Item Item;

/// ====
/// Defines
/// ====


/// ====
/// Prototypes
/// ====
Item *item_Constructor();
void item_Deconstructor(Item *item);

/// ====
/// Structures
/// ====

struct Queue
{
    int length;
    Item *head;
    Item *tail;
};

struct Item
{
    int value;
    Item *next;
    Item *prev;
};

/// ====
/// Constructors and Destructor
/// ====
Queue *queue_Constructor() {}
void queue_Deconstructor(Queue *queue) {}

Item *item_Constructor() {}
void item_Deconstructor(Item *item) {}

/// ====
/// Public Functions
/// ====


/// ====
/// Helper Functions
/// ====