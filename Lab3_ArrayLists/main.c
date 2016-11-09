#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    printf("Makeing an list!\n");

    struct List* test_List;
    test_List = list_Constructor();

    int i = 0;
    while ( 1 )
    {
        int value = list_Add(test_List,i*i);
        if (value <= 0)
        {
            break;
        }
        i++;
    }

    list_Display(test_List);

    printf("\n\n");

    int value = 0;

    int result = list_Read(test_List,1,&value);

    printf("the second(index=1) element in the list is : [ %d ]\n",value);


    int found = list_Search(test_List,81);
    printf("searching for a value of 81 in the list, it is in position : [ %d ]\n",found);



    list_Remove(test_List , 1);
    list_Display(test_List);


	printf("\n");


	printf("\nPRESS ANY KEY TO CONTINUE\n");
	getch();

    return 0;
}
