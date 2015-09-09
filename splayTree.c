# include <stdio.h>
# include <stdlib.h>
# include "splayTree.h"

void initSplayTree ( SplayTree ** node )
{
	(*node) = (SplayTree *)malloc(sizeof(SplayTree *));
	(*node)->left = NULL;
	(*node)->right = NULL;
	(*node)->parent = NULL;
}

void leftRotate(SplayTree *node)
{
	SplayTree *tmp;
	
	tmp = node->right;								 contorSplay = contorSplay + 2; //antet if si atribuire
	if ( tmp != NULL )                              
	{
		node->right = tmp->left;                     contorSplay = contorSplay + 9; // tot ce este in if
		if ( tmp->left != NULL ) 
			tmp->left->parent = node;
		tmp->parent = node->parent; 
	}
													 contorSplay = contorSplay + 2 + 3; // totat structura if else am analizat-o dintro bucata. 2 pentru fiecare antet if si 3 pentru unul din if-urile pe care intra
	if ( node->parent == NULL ) node->parent = tmp;
	else if ( node == node->parent->left ) //check if our note is a left child or a right child
			node->parent->left = tmp;
		else node->parent->right = tmp;
													 contorSplay = contorSplay + 3; //antet if, pointare si atribuire + 1/2 din cazul in care intra pe if
	if (tmp != NULL )
		tmp->left = node;
	node->parent = tmp; // we put our note do the left of the new root
}

void rightRotate (SplayTree *node)
{
	SplayTree *tmp;
	//put the pointer of the left subtree of the node in tmp 
	tmp = node->left;									contorSplay = contorSplay + 2; //antet if si atribuire
	if (tmp != NULL )
	{		
		node->left = tmp->right;                        contorSplay = contorSplay + 9; // tot ce este in if
		if ( tmp->right != NULL )
			tmp->right->parent = node;
		tmp->parent = node->parent;
	}

														contorSplay = contorSplay + 2 + 3; // totat structura if else am analizat-o dintro bucata. 2 pentru fiecare antet if si 3 pentru unul din if-urile pe care intra
	if ( node->parent == NULL )	node->parent = tmp;
	else if ( node == node->parent->left ) //check if our note is a left child or a right child
			node->parent->left = tmp;
		else node->parent->right = tmp;
														contorSplay = contorSplay + 4; //antet if, pointare si atribuire + 1/2 din cazul in care intra pe if
	if (tmp != NULL )
		tmp->right = node;
	node->parent = tmp; //we put our node to the right of the new root
}

SplayTree* getRoot(SplayTree **node)
{
	while ( (*node)->parent != NULL )
		(*node) = (*node)->parent;

	return (*node);
}

void splayCreate( SplayTree *x)
{
	while ( x->parent != NULL ) //While we are not at the root
	{
		//CASE 1! ZIG STEP
													contorSplay = contorSplay + 3; // antet if: 2 pointeri si o comparatie
		if ( x->parent->parent == NULL )                                               // The zig step. if x is the child of the root we have 2 cases:
		{
													contorSplay = contorSplay + 3 + 1; // 3 pentru if si 1 pentru apelarea functiei
			if ( x->parent->left == x )                                             // a. if x is the left child of the root
				rightRotate(x->parent);                                               // we rotate to the right
			else if ( x->parent->right == x )                                       // b. if x is the right child of the root
					leftRotate(x->parent);                                            // we rotate to the left
		}
		//CASE 2! ZIG-ZIG STEP
		else
			if ( x->parent->left == x && x->parent->parent->left == x->parent ) // 1. if x is the left child of a left child
			{
																contorSplay = contorSplay + 2; //apelarea functiilor
				rightRotate(x->parent->parent);                                          // We rotate first through the grand-parrent.
				rightRotate(x->parent);                                                // Then we rotate though the partent
			}
			else
				if ( x->parent->right == x && x->parent->parent->right == x->parent ) // 2. if x is the right child of a right child
				{
																contorSplay = contorSplay + 2; //apelarea functiilor
					leftRotate(x->parent->parent);                                        // We rotate first through the grand-parrent.
					leftRotate(x->parent);                                                    // Then we rotate though the partent
				}
		//CASE 3! ZIG-ZAG STEP
		else
			if ( x->parent->left == x && x->parent->parent->right == x->parent )     // 1. if x is the left child of a right child
			{
																contorSplay = contorSplay + 2; //apelarea functiilor
				rightRotate(x->parent);                                                      // We rotate to the right    
				leftRotate(x->parent);                                                       // Then we rotate to the left
			}
			else
				if ( x->parent->right == x && x->parent->parent->left == x->parent ) // 2. if x is the right child of a left child
				{
																contorSplay = contorSplay + 2; //apelarea functiilor
					leftRotate(x->parent);                                                   // We rotate to the left
					rightRotate(x->parent);                                                  // Then we rotate to the right
				}

		//PENTRU A NU STRICA CUM ARATA CODUL, AM ALES SA FAC URMATORUL ARTIFICU:
				//Calculam cate operatii are fiecare antet ar if-urilor care verifica cazurile 1, 2 si 3 => fiecare if are 9 operatii elementare =>	
								//contorSplay = contorSplay + 9;
				//Acum presupunem ca numarul de accesari, la o signura rulare, al fiecarui if este de jumatare de ori din totalul lor: accesari = #if/2 => accesari = 5/2 = 2.5
				//Acum impartim operatii simple la accesari => 9/2.5 = 3.6. facem partea intreaga superioara si vom avea: contorSplay = contorSplay + 4
					contorSplay = contorSplay + 4;
	}
}

void splayTreeInsert(SplayTree **splayTree, SplayTree *parent, SplayTree *value)
{
	if ( !(*splayTree))
	{
		*splayTree = value;                                  contorSplay = contorSplay + 1; //am decis a introducerea unui nou element in arbore sa fie contorizata cu 1!!
		(*splayTree)->parent = parent;
		(*splayTree)->left = NULL;
		(*splayTree)->right = NULL;

		//We create the splay Tree
		splayCreate(*splayTree);							 contorSplay = contorSplay + 1; // apelarea lui splayCreate
		return;
	}
	else
	{
															contorSplay = contorSplay + 3; //if-ul: o comparatie si 2 pointeri
		if ( value->key < (*splayTree)->key ) 
		{
															contorSplay = contorSplay + 1; // apelarea functiei
			splayTreeInsert(&(*splayTree)->left, (*splayTree), value); //if the new element is less than the node's key, we go to the left
		}
		else
		{
															contorSplay = contorSplay + 3; //if-ul: o comparatie si 2 pointeri
			if ( value->key > (*splayTree)->key )
			{
															contorSplay = contorSplay + 1; // apelarea functiei
				splayTreeInsert(&(*splayTree)->right, (*splayTree), value); //if the new element is greater than the node's key, we go to the right
			}
			else
			{
															contorSplay = contorSplay + 3; //if-ul: o comparatie si 2 pointeri
				if ( value->key == (*splayTree)->key )
				{
															contorSplay = contorSplay + 1; // apelarea functiei
					splayTreeInsert(&(*splayTree)->right, (*splayTree),value); // if the new element is equal to node's key, we go to the right
				}
			}
		}
	}
}

//Am decis sa nu contorizez printarea deoarece nu tine de algoritmul de sortare!
void inorderPrintSplayTree ( SplayTree *splayTree )
{
	if ( NULL != splayTree )
	{	
		inorderPrintSplayTree ( splayTree->left );
		printf("%d ", splayTree->key);
		inorderPrintSplayTree ( splayTree->right );	
	}
}


void splaySort ( SplayTree **splayTree, int size, int vector[])
{
	//1. initialize the tree
	//2. insert element into splayTree
	//3. print the splay tree in inorder
	int i;
	SplayTree *aux, *root;
	aux = NULL;
	root = NULL;
	for ( i = 0; i < size; i++ )
	{
		aux = (SplayTree *)malloc(sizeof(SplayTree));                 contorSplay = contorSplay + 6; //tot ce este in for + antetul lui
		aux->key = vector[i];	
		splayTreeInsert(splayTree, NULL ,aux);
		*splayTree = getRoot(splayTree); // ROOOOT! YESS!! 
		//if we dont call the splayTreeInsert function always on the root, we have a little big problem and the tree get's unbalanced!
	}
	


}