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

Item *itemConstructor(int value);
void itemDeconstructor(Item *item);


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

Queue *queue_Constructor()
{
    Queue *queue;
    queue = malloc(sizeof(Queue));
    
    queue->length = 0;
    queue->head = NULL;
    queue->tail = NULL;
    
    return queue;
}

void queue_Deconstructor(Queue *queue)
{
    Item *curr;
    Item *next = queue->head;
    
    while (next != NULL)
    {
        curr = next;
        next = curr->next;
        itemDeconstructor(curr);
    }
    
    free(queue);
    
}

Item *itemConstructor(int value)
{
    Item *item;
    item = malloc(sizeof(Item));
    
    item->value = value;
    item->next = NULL;
    item->prev = NULL;
    
    return item;
}

void itemDeconstructor(Item *item)
{
    free(item);
}


/// ====
/// Public Functions
/// ====

// returns 1 if queue is empty, 0 if queue isnt empty, -1 if queue is NULL
int queue_isEmpty(Queue *queue)
{
    if (queue == NULL)
    {
        return -1;
    }
    
    if (queue->head == NULL || queue->tail == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

// returns 1 if enqueue was successful, -1 if queue is null
int queue_Enqueue(Queue *queue, int value)
{
    if (queue == NULL)
    {
        return -1;
    }
    
    Item *item = itemConstructor(value);
    
    queue->head->prev = item;
    item->next = queue->head;
    item->prev = NULL;
    queue->head = item;
    
    queue->length++;
    
    return 1;
    
}

// returns 1 if dequeue was successful, 0 if it was unsuccessful, -1 if queue is null
int queue_Dequeue(Queue *queue, int *dequeuedvalue)
{
    if (queue == NULL)
    {
        return -1;
    }
    
    if ((queue->length == 0) || (queue->head == NULL && queue->tail == NULL))
    {
        return 0;
    }
    
    Item *last = queue->tail;
    
    last->prev->next = NULL;
    queue->tail = last->prev;
    
    itemDeconstructor(last);
    
    return 1;
}

int queue_Peek(Queue *queue, int index, int *peeked)
{
    if (queue == NULL)
    {
        return -1;
    }
    
    if (index < 0 || index >= queue->length)
    {
        return 0;
    }
    
    Item *item = queue->tail;
    
    for (int j = 0; j < index; j++)
    {
        item = item->prev;
    }
    
    (*peeked) = item->value; //might be off by one index?
    
    return 1;
}



/// ====
/// Helper Functions
/// ====