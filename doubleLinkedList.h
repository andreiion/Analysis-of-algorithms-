#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H

typedef struct linkedList LinkedList;
struct linkedList
{
	LinkedList *prev;
	int key;
	LinkedList *next;
};

void initializeDoubleList ( LinkedList **list);
LinkedList* headDoubleList(LinkedList **list);
int doubleListSearch( LinkedList **list, int key );
void doubleListInsert( LinkedList **list, LinkedList *node );
void doubleistDelete( LinkedList **list, LinkedList *node );
LinkedList* listConcat( LinkedList **listA, LinkedList **listB);


#endif