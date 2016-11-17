#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"


/// ====
/// Defines
/// ====
#define ITEMS_IN_SORTS_TEST 1000


/// ====
/// Prototypes
/// ====
int main();
void testBubbleSortSpeed(int num);
void testInsertionSortSpeed(int num);
void testQuickSortSpeed(int num);
void testBubbleSort();
void testOrderedAdd();
void testInsertionSort();
void testQuickSort();


/// ====
/// Functions
/// ====
int main()
{
    printf("\n####\t SORTS \n\n");
    
    
    testBubbleSortSpeed(ITEMS_IN_SORTS_TEST);
    testInsertionSortSpeed(ITEMS_IN_SORTS_TEST);
    testQuickSortSpeed(ITEMS_IN_SORTS_TEST);
    
    
    
    printf("\n\n####\t Press Any Key to Continue\n");
    getchar();
    
    return 0;
}

void testBubbleSortSpeed(int num)
{
    printf("\n####\t BUBBLE SORT SPEED TEST \n\t\t\t\t\t");
    
    
    struct List *forward_list = list_Constructor();
    
    int i;
    
    for (i = 0; i < num; i++)
    {
        list_Add(forward_list, i);
    }
    
    struct List *backward_list = list_Constructor();
    
    for (i = 0; i < num; i++)
    {
        list_Add(backward_list, (num - i));
    }
    
    struct List *random_list = list_Constructor();
    
    
    for (i = 0; i < num; i++)
    {
        list_Add(random_list, rand() % 100);
    }
    
    //////////////////// DO TESTS //////////////////////////////////
    
    clock_t startTime, endTime, elapsed;
    
    startTime = clock();
    list_BubbleSort(forward_list);
    endTime = clock();
    elapsed = endTime - startTime;
    printf("FORWARD:: %lf\t", (double)elapsed);
    
    startTime = clock();
    list_BubbleSort(backward_list);
    endTime = clock();
    elapsed = endTime - startTime;
    printf("BACKWARD:: %lf\t", (double)elapsed);
    
    startTime = clock();
    list_BubbleSort(random_list);
    endTime = clock();
    elapsed = endTime - startTime;
    printf("RANDOM:: %lf\n", (double)elapsed);
    
}

void testInsertionSortSpeed(int num)
{
    printf("\n####\t INSERTION SORT SPEED TEST \n\t\t\t\t\t");
    
    
    struct List *forward_list = list_Constructor();
    
    int i;
    
    for (i = 0; i < num; i++)
    {
        list_Add(forward_list, i);
    }
    
    struct List *backward_list = list_Constructor();
    
    for (i = 0; i < num; i++)
    {
        list_Add(backward_list, (num - i));
    }
    
    struct List *random_list = list_Constructor();
    
    
    for (i = 0; i < num; i++)
    {
        list_Add(random_list, rand() % 100);
    }
    
    //////////////////// DO TESTS //////////////////////////////////
    
    clock_t startTime, endTime, elapsed;
    
    startTime = clock();
    list_InsertionSort(forward_list);
    endTime = clock();
    elapsed = endTime - startTime;
    printf("FORWARD:: %lf\t", (double)elapsed);
    
    startTime = clock();
    list_InsertionSort(backward_list);
    endTime = clock();
    elapsed = endTime - startTime;
    printf("BACKWARD:: %lf\t", (double)elapsed);
    
    startTime = clock();
    list_InsertionSort(random_list);
    endTime = clock();
    elapsed = endTime - startTime;
    printf("RANDOM:: %lf\n", (double)elapsed);
    
    
}

void testQuickSortSpeed(int num)
{
    printf("\n####\t QUICK SORT SPEED TEST \n\t\t\t\t\t");
    
    
    struct List *forward_list = list_Constructor();
    
    int i;
    
    for (i = 0; i < num; i++)
    {
        list_Add(forward_list, i);
    }
    
    struct List *backward_list = list_Constructor();
    
    for (i = 0; i < num; i++)
    {
        list_Add(backward_list, (num - i));
    }
    
    struct List *random_list = list_Constructor();
    
    
    for (i = 0; i < num; i++)
    {
        list_Add(random_list, rand() % 100);
    }
    
    //////////////////// DO TESTS //////////////////////////////////
    
    clock_t startTime, endTime, elapsed;
    
    startTime = clock();
    list_QuickSort(forward_list);
    endTime = clock();
    elapsed = endTime - startTime;
    printf("FORWARD:: %lf\t", (double)elapsed);
    
    startTime = clock();
    list_QuickSort(backward_list);
    endTime = clock();
    elapsed = endTime - startTime;
    printf("BACKWARD:: %lf\t", (double)elapsed);
    
    startTime = clock();
    list_QuickSort(random_list);
    endTime = clock();
    elapsed = endTime - startTime;
    printf("RANDOM:: %lf\n", (double)elapsed);
    
}

void testBubbleSort()
{
    /// TEST MAKE LIST
    
    struct List *test_list = list_Constructor();
    
    int i;
    
    for (i = 0; i < 10; i++)
    {
        list_Add(test_list, (10 - i) * (10 - i));
    }
    
    printf("\n\t Initial list \n");
    
    list_Display(test_list);
    
    printf("\n\n####\t Press Any Key to Continue\n");
    getchar();
    
    /// TEST BUUBLE SORT
    
    list_BubbleSort(test_list);
    
    printf("\n\t Bubble sorted list \n");
    
    list_Display(test_list);
    
    printf("\n\n####\t Press Any Key to Continue\n");
    getchar();
    
    /// TEST RANDOM LIST
    
    struct List *random_list = list_Constructor();
    
    
    int j;
    
    for (j = 0; j < 10; j++)
    {
        list_Add(random_list, rand() % 100);
    }
    
    printf("\n\t Random list \n");
    
    list_Display(random_list);
    
    printf("\n\n####\t Press Any Key to Continue\n");
    getchar();
    
    /// TEST RANDOM BUBBLE SORT
    
    list_BubbleSort(random_list);
    
    printf("\n\t Bubble Sorted Random list \n");
    
    list_Display(random_list);
    
    printf("\n\n####\t Press Any Key to Continue\n");
    getchar();
}

void testOrderedAdd()
{
    /// TEST RANDOM LIST
    
    struct List *random_list = list_Constructor();
    
    
    int j;
    
    for (j = 0; j < 10; j++)
    {
        list_Add(random_list, rand() % 100);
    }
    
    printf("\n\t Random list \n");
    
    list_Display(random_list);
    
    printf("\n\n####\t Press Any Key to Continue\n");
    getchar();
    
    /// TEST ORDERED ADD
    
    list_AddOrdered(random_list, 75);
    
    printf("\n\t AddOrdered 75 to list \n");
    
    list_Display(random_list);
    
    printf("\n\n####\t Press Any Key to Continue\n");
    getchar();
    
    /// TEST ORDERED ADD
    
    list_AddOrdered(random_list, -1);
    
    printf("\n\t AddOrdered -1 to list \n");
    
    list_Display(random_list);
    
    printf("\n\n####\t Press Any Key to Continue\n");
    getchar();
    
    /// TEST ORDERED ADD
    
    list_AddOrdered(random_list, 101);
    
    printf("\n\t AddOrdered 101 to list \n");
    
    list_Display(random_list);
    
    printf("\n\n####\t Press Any Key to Continue\n");
    getchar();
}

void testInsertionSort()
{
    /// TEST RANDOM LIST
    
    struct List *random2_list = list_Constructor();
    
    int k;
    
    for (k = 0; k < 10; k++)
    {
        list_Add(random2_list, rand() % 100);
    }
    
    printf("\n\t a new  Random list \n");
    
    list_Display(random2_list);
    
    printf("\n\n####\t Press Any Key to Continue\n");
    getchar();
    
    /// TEST RANDOM INSERTION SORT
    
    list_InsertionSort(random2_list);
    
    printf("\n\t Insertion sorted list\n");
    list_Display(random2_list);
    
    printf("\n\n####\t Press Any Key to Continue\n");
    getchar();
    
    /// TEST BINARY SEARCH
    int t = -2;
    int *target = &t;
    list_Read(random2_list, 4, target);
    int targetIndex = list_BinarySearch(random2_list, *target);
    
    printf("\n\t Binary Search list: value %d found at %d\n", *target, targetIndex);
    list_Display(random2_list);
    
    printf("\n\n####\t Press Any Key to Continue\n");
    getchar();
}


void testQuickSort()
{
    /// TEST RANDOM LIST
    
    struct List *random3_list = list_Constructor();
    
    int l;
    
    for (l = 0; l < 20; l++)
    {
        list_Add(random3_list, rand() % 100);
    }
    
    printf("\n\t a new  Random list \n");
    
    list_Display(random3_list);
    
    printf("\n\n####\t Press Any Key to Continue\n");
    getchar();
    
    /// TEST RANDOM Quick SORT
    
    list_QuickSort(random3_list);
    
    printf("\n\t Quick sorted list\n");
    list_Display(random3_list);
    
    printf("\n\n####\t Press Any Key to Continue\n");
    getchar();
}

