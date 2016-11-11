//#define NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack.h"
#include "Queue.h"


/// ====
/// Prototypes
/// ====
void testMakeQueue();


/// ====
/// Main
/// ====
int main(void)
{
    testMakeQueue();
    
    printf("\n\t\tpress enter to exit\n");
    getchar();
    
    return 0;
}

/// ====
/// Functions
/// ====
void testMakeQueue()
{
    Queue *queue = queue_Constructor();
    
    assert(queue_isEmpty(queue) == 1 && "assert that the result of queue_isEmpty() on an empty list is 1");
    
    int val1 = 10;
    assert(queue_Enqueue(queue, 10) == 1 && "assert that we were succesful at queue_Enqueue() on an empty list");
    assert(queue_isEmpty(queue) == 0 && "assert that the result of queue_isEmpty() on a list with a single elememnt is 0");
    
    int a = 0;
    assert(queue_Peek(queue, 0, &a) == 1 && "assert that the result of queue_Peek() on a valid index is 1" );
    assert(a == val1 && "assert that the result of queue_Peek() is the same as the value we enqueued");
    
    int b = 0;
    assert(queue_Dequeue(queue, &b) == 1 && "assert that the result of queue_Dequeue() is 1 when there is a item to dequeue");
    assert(b == val1 && "assert that the result of queue_Dequeue() is the same as the value we enqueued");
    
    
    
}