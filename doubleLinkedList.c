# include <stdio.h>
# include <stdlib.h>
# include "linkedList.h"


void initializeDoubleList ( LinkedList **list)
{
	(*list) = (LinkedList *)malloc(sizeof(LinkedList *));
	(*list)->next = NULL;
	(*list)->prev = NULL;
	
}

//Returns the first element of the list
LinkedList* head (LinkedList **list)
{
	LinkedList *newNode = *list;
	while (newNode->prev != NULL)
		newNode = newNode->prev;
	return newNode;
}

int listSearch( LinkedList **list, int key )
{
	LinkedList *node = head(list);
	while ( NULL != node && node->key != key )
		node = node->next;
	return key;
}

void listInsert( LinkedList **list, LinkedList *node )
{
	node->next = head(list);
	if ( NULL != head(list) )
		node->next->prev = node;
	node->next = node;
	node->prev = NULL;
}

void listDelete( LinkedList **list, LinkedList *node )
{

}

LinkedList* listConcat ( LinkedList **listA, LinkedList **listB )
{
	LinkedList *listAux = *(listA);
	while ( listAux->next != NULL )
		listAux = listAux->next;
	listAux->next = *listB;

	return *listA;
}