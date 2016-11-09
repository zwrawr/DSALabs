#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    printf("Makeing an list!\n");

    struct List* test_List;
    test_List = list_Constructor();

    int i = 0;
    while ( i < 10 )
    {
        printf("add : ");
        int value = list_Add(test_List,i*i);
        if (value <= 0)
        {
            break;
        }
        i++;
    }

    printf("\n\n");

    list_Display(test_List);

    printf("\n\n");

    int value = 0;

    int result = list_Read(test_List,1,&value);
    printf("the second(index=1) element in the list is : [ %d ]\n",value);

    result = list_Read(test_List,3,&value);
    printf("the forth(index=3) element in the list is : [ %d ]\n",value);


    printf("\n");


    int found = list_Search(test_List,81);
    printf("searching for a value of 81 in the list, it is in position : [ %d ]\n",found);

    found = list_Search(test_List,25);
    printf("searching for a value of 25 in the list, it is in position : [ %d ]\n",found);



    list_Remove(test_List , 1);
    list_Display(test_List);

	printf("\n");


	printf("\nPRESS ANY KEY TO CONTINUE\n");
	getch();


    return 0;
}
