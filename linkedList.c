# include <stdio.h>
# include <stdlib.h>
# include "linkedList.h"

void initializeList ( LinkedList **list)
{
	(*list) = (LinkedList *)malloc(sizeof(LinkedList*));
	(*list)->next = NULL;	
}

void insertList (LinkedList **list, int value)
{
	while ( (*list)->next != NULL )
	{
		(*list) = (*list)->next;
	}
	(*list)->next = (LinkedList *)malloc(sizeof(LinkedList *));
	(*list) = (*list)->next;
	(*list)->key = value;
	(*list)->next = NULL;
}

void insertList2 (LinkedList **list, int value)
{
	if ( (*list) == NULL )
	{
		(*list) = (LinkedList *)malloc(sizeof(LinkedList *));
		(*list)->next = NULL;
		(*list)->key = value;
	}
	while ( (*list)->next != NULL )
	{
		(*list) = (*list)->next;
	}
	(*list)->next = (LinkedList *)malloc(sizeof(LinkedList *));
	(*list) = (*list)->next;
	(*list)->key = value;
	(*list)->next = NULL;
}


void insert_node_to_List (LinkedList **list, LinkedList *node)
{
	LinkedList *aux;
	aux = (*list);
	if (*list == NULL )
	{
		(*list) = node;
		(*list)->next = NULL;
		return;
	}
	while ( aux->next != NULL )
	{
		aux = aux->next;
	}
	aux->next = node;
	node->next = NULL;
}

void printList ( LinkedList **list )
{
	if ( (*list) == NULL )
		return;

	printf ("%d ", (*list)->key);
	printList(&(*list)->next);
}

int interclass( LinkedList **a, LinkedList *b)
{
	LinkedList *aux, *aux2=NULL;
	int contor = 0;
	aux = NULL;
	while ( b != NULL && (*a) != NULL )
	{										 contor = contor + 6; //antet while si antet if
		if ( (*a)->key > b->key )
		{									 contor = contor + 2 + 8 + 1; //inserarea + 2 atribuiri si o pointare
			aux2 =b->next;
			insert_node_to_List(&aux, b);
			b = aux2;
		}
		else
		{									 contor = contor + 2 + 8 + 1; //inserarea + 2 atribuiri si o pointare					
			aux2 = (*a)->next;
			insert_node_to_List(&aux, (*a));
			(*a) = aux2;
		}
	}

	while ( b != NULL )
	{										contor = contor + 2 + 8 + 1 + 1; //inserarea + 2 atribuiri si o pointare + antet while
		aux2 = b->next;
		insert_node_to_List(&aux, b);
		b = aux2;
	}
	while ( *a != NULL )
	{										contor = contor + 2 + 8 + 1 + 1; //inserarea + 2 atribuiri si o pointare + antet while
		aux2 = (*a)->next;
		insert_node_to_List(&aux, (*a));
		(*a) = aux2 ;
	}

	(*a) = aux;

	return contor + 1;
}


int listToVector( LinkedList *list, int arr[])
{
	int i = 0, contor = 0;
	while ( list != NULL )
	{
									contor = contor + 7;
		arr[i++] = list->key;
		list = list->next;
	}

	return contor;
}

int vectorToList ( LinkedList *list, int arr[], int size )
{
	int i, contor = 0;
	
	for ( i = 1; i < size; i++ )
	{
									contor = contor + 3 + 8; //for-ul si inserarea 
		insertList(&list, arr[i]);
	}
	return contor;
}

void removeFromList ( LinkedList **lista, int x)
{
	LinkedList *node = *lista;
	LinkedList *elim = *lista;

	if ( (*lista) == NULL)
		return;
	if (node->key == x)
	{
		elim = node;
		*lista = node->next;
		//free(elim);
		elim = NULL;
	}
	else
	{
		while(node->next != NULL && x != node->next->key)
			node = node->next;
		elim = node->next;
		if (node->next != NULL)
		{
			node->next = node->next->next;
			//*lista = node->leg;
		}
		//free(elim);
		elim = NULL;
	}
	//free(&elim);
}
