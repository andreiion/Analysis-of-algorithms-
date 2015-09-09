#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct linkedList LinkedList;
struct linkedList
{
	int key;
	LinkedList *next;
};


void initializeList ( LinkedList **list);
void insertList ( LinkedList **list, int value );

void printList ( LinkedList **list );

int interclass( LinkedList **a, LinkedList *b);
void insert_node_to_List (LinkedList **list, LinkedList *node);
void insert_node_to_List2 (LinkedList *list, LinkedList *node);
int listToVector( LinkedList *list, int arr[]);
int vectorToList ( LinkedList *list, int arr[], int size );
void removeFromList ( LinkedList **lista, int x);
void insertList2 (LinkedList **list, int value);

#endif