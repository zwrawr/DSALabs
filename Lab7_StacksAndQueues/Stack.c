#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


/// ====
/// Defines
/// ====
#define INITIAL_STACK_LENGTH 10

/// ====
/// Prototypes
/// ====


/// ====
/// Structures
/// ====
struct Stack
{
    int length;
    int top;
    int *array;
};

/// ====
/// Constructors and Destructor
/// ====
Stack *stack_Constructor()
{
    Stack *stack;
    stack = malloc(sizeof(Stack));
    
    stack->length = INITIAL_STACK_LENGTH;
    stack->top = 0;
    stack->array = malloc(stack->length * sizeof(int));
    
    return stack;
}

void stack_Deconstructor(Stack *stack)
{
    free(stack->array);
    free(stack);
}

/// ====
/// Public Functions
/// ====

// returns 1 if stack is empty, 0 if stack isnt empty, -1 if stack is NULL
int stack_isEmpty(Stack *stack)
{
    if (stack == NULL)
    {
        return -1;
    }
    
    if (stack->top == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// returns 1 if stack is full, 0 if stack isnt full, -1 if stack is NULL
int stack_isFull(Stack *stack)
{
    if (stack == NULL)
    {
        return -1;
    }
    
    
    if (stack->top == (stack->length - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// returns 1 if push was successful, 0 if it was unsuccsessful, -1 if stack is NULL
int stack_Push(Stack *stack, int value)
{
    if (stack == NULL)
    {
        return -1;
    }
    
    if (stack_isFull(stack) != 0)
    {
        stack->length *= 2;
        stack->array = realloc(stack->array, stack->length * sizeof(int));
    }
    
    stack->array[stack->top] = value;
    stack->top++;
    
    return 1;
}

// returns 1 if pop was successful, 0 if it was unsuccsessful, -1 if stack is NULL
int stack_Pop(Stack *stack, int *popped)
{
    if (stack == NULL)
    {
        return -1;
    }
    
    if (stack_isEmpty(stack) == 0)
    {
        stack->top--;
        (*popped) = stack->array[stack->top];
        return 1;
    }
    else
    {
        return 0;
    }
}

// returns 1 if peek was successful, 0 if it was unsuccsessful, -1 if stack is NULL
int stack_Peek(Stack *stack, int index, int *peeked)
{
    if (stack == NULL)
    {
        return -1;
    }
    
    if (index < 0 || index > stack->top)
    {
        return 0;
    }
    
    (*peeked) = stack->array[index];
    
    return 1;
}


/// ====
/// Helper Functions
/// ====