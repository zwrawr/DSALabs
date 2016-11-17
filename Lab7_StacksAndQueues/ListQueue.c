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
    Item *front;
    Item *back;
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
    queue->front = NULL;
    queue->back = NULL;
    
    return queue;
}

void queue_Deconstructor(Queue *queue)
{
    Item *curr;
    Item *next = queue->front;
    
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
    
    if (queue->length == 0)
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
    
    if (queue->length == 0)
    {
        queue->front = item;
        queue->back = item;
        item->next = NULL;
        item->prev = NULL;
    }
    else
    {
        queue->front->prev = item;
        item->next = queue->front;
        item->prev = NULL;
        queue->front = item;
    }
    
    queue->length++;
    
    return 1;
    
}

// returns 1 if dequeue was successful, 0 if it was unsuccessful, -1 if queue is null
int queue_Dequeue(Queue *queue, int *dequeuedvalue)
{
    if (queue == NULL)
    {
        // this queue hasnt been initialized
        return -1;
    }
    
    if (queue->length == 0)
    {
        // nothing to dequeue
        return 0;
    }
    
    Item *last = queue->back;
    (*dequeuedvalue) = last->value;
    
    if (queue->length == 1)
    {
        // queue will be empty once we dequeue this item
        queue->back = NULL;
        queue->front = NULL;
        
        queue->length = 0;
    }
    else
    {
        last->prev->next = NULL;
        queue->back = last->prev;
        
        queue->length--;
    }
    
    itemDeconstructor(last);
    
    return 1;
}

// returns 1 if peek was successful, 0 if it was unsuccessful, -1 if queue is null
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
    
    Item *item = queue->back;
    
    for (int j = 0; j < index; j++)
    {
        item = item->prev;
    }
    
    (*peeked) = item->value; //might be off by one index?
    
    return 1;
}

void queue_Display(Queue *queue)
{
    printf("\t\t\t= QUEUE \t[ ");
    
    Item *item = queue->back;
    
    for (int i = 0; i < queue->length; i++)
    {
        printf(" %d:(%d) ", i, item->value);
        
        item = item->prev;
        
    }
    
    printf(" ] \n");
}


/// ====
/// Helper Functions
/// ====