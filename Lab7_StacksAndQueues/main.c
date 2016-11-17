//#define NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack.h"
#include "Queue.h"


/// ====
/// Prototypes
/// ====
void test_MakeQueue();
void test_LargeQueue();
void test_MakeStack();
void test_LargeStack();

/// ====
/// Main
/// ====
int main(void)
{
    test_MakeQueue();
    test_LargeQueue();
    
    test_MakeStack();
    test_LargeStack();
    
    printf("\n\t\tpress enter to exit\n");
    getchar();
    
    return 0;
}

/// ====
/// Functions
/// ====
void test_MakeQueue()
{
    printf("= Make Queue\n");
    
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
    
    queue_Deconstructor(queue);
    
}

void test_LargeQueue()
{
    printf("= Large Queue\n");
    
    int test_size = 10000;
    int *test_values = malloc(test_size * sizeof(int));
    
    Queue *test_queue = queue_Constructor();
    
    // populate queue
    printf("=\tpopulate queue\n");
    
    for (int i = 0 ; i < test_size; i++ )
    {
        int success = queue_Enqueue(test_queue, i * 2);
        assert(success == 1 && "assert return value of queue_Enqueue is 1");
        test_values[i] = i * 2;
    }
    
    queue_Display(test_queue);
    
    // peek at queue
    printf("=\tpeek at queue\n");
    
    for (int i = 0; i < test_size; i++)
    {
        int a = -1;
        int success = queue_Peek(test_queue, i, &a);
        assert(success == 1 && "assert return value of queue_peek is 1");
        assert(test_values[i] == a && "assert that peeked value is as expected");
    }
    
    // depopulate queue
    printf("=\tdepopulate queue\n");
    
    for (int i = 0; i < test_size; i++)
    {
        int a = -1;
        int success = queue_Dequeue(test_queue, &a);
        assert(success == 1 && "assert return value of queue_Enqueue is 1");
        assert(test_values[i] == a && "assert that dequeue value is as expected");
    }
    
    // deconstruct queue
    printf("=\tdeconstruct queue\n");
    queue_Deconstructor(test_queue);
}

void test_MakeStack()
{
    printf("= Make Stack\n");
    
    Stack *stack = stack_Constructor();
    
    assert(stack_isEmpty(stack) == 1 && "assert that the result of stack_isEmpty() on an empty stack is 1");
    
    int val1 = 10;
    assert(stack_Push(stack, 10) == 1 && "assert that we were succesful at stack_Push() on an empty stack");
    assert(stack_isEmpty(stack) == 0 && "assert that the result of stack_isEmpty() on a stack with a single elememnt is 0");
    
    int a = 0;
    assert(stack_Peek(stack, 0, &a) == 1 && "assert that the result of stack_Peek() on a valid index is 1");
    assert(a == val1 && "assert that the result of stack_Peek() is the same as the value we enqueued");
    
    int b = 0;
    assert(stack_Pop(stack, &b) == 1 && "assert that the result of stack_Pop() is 1 when there is a item to dequeue");
    assert(b == val1 && "assert that the result of stack_Pop() is the same as the value we enqueued");
    
}

void test_LargeStack()
{
    printf("= Large Stack\n");
    
    int test_size = 10000;
    int *test_values = malloc(test_size * sizeof(int));
    
    Stack *test_stack = stack_Constructor();
    
    // populate stack
    printf("=\tpopulate stack\n");
    
    for (int i = 0; i < test_size; i++)
    {
        int success = stack_Push(test_stack, i * 2);
        assert(success == 1 && "assert return value of stack_Push is 1");
        test_values[i] = i * 2;
    }
    
    // peek at stack
    printf("=\tpeek at stack\n");
    
    for (int i = 0; i < test_size; i++)
    {
        int a = -1;
        int success = stack_Peek(test_stack, i, &a);
        assert(success == 1 && "assert return value of stack_Peek is 1");
        assert(test_values[i] == a && "assert that peeked value is as expected");
    }
    
    // depopulate stack
    printf("=\tdepopulate stack\n");
    
    for (int i = 0; i < test_size; i++)
    {
        int a = -1;
        int success = stack_Pop(test_stack, &a);
        assert(success == 1 && "assert return value of stack_Pop is 1");
        assert(test_values[test_size - i - 1] == a && "assert that poped value is as expected");
    }
    
    // deconstruct stack
    printf("=\tdeconstruct stack\n");
    stack_Deconstructor(test_stack);
}