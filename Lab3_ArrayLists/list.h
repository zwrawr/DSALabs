#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

/// ====
/// Structures
/// ====
struct List;


/// ====
/// Constructors and Destructor
/// ====
struct List *list_Constructor();
void list_Destructor(struct List *list);


/// ====
/// Functions
/// ====
int list_Add(struct List *list, int entity);
void list_Display(struct List *list);
int list_Read(struct List *list, int index, int *entity);
int list_Search(struct List *list, int entity);
int list_Remove(struct List *list, int index);
int list_Size(struct List *list);
int list_isEmpty(struct List *list);


#endif // LIST_H_INCLUDED
