# include <stdio.h>
# include <stdlib.h>
# include "binaryTree.h"



/****************************************************************************/
/*************                Tree Sort	    	    	********************/
/**************************************************************************/

void treeInsert( BinaryTree **binaryTree, BinaryTree *value )
{
	contorTree = contorTree + 1;
	if ( !(*binaryTree))
	{												
		*binaryTree = value;						contorTree = contorTree + 1; // am decis ca introducerea unui nou element sa fie o operatie elementara!!
		(*binaryTree)->left = NULL;
		(*binaryTree)->right = NULL;
		return;
	}
	else
	{
		contorTree = contorTree + 3; //if-ul: o comparatie si 2 pointeri
		if ( value->key < (*binaryTree)->key ) 
		{
			contorTree = contorTree + 1; //apelarea functiei
			treeInsert(&(*binaryTree)->left, value); //if the new element is less than the node's key, we go to the left
		}
		else
		{
			contorTree = contorTree + 3; //if-ul: o comparatie si 2 pointeri
			if ( value->key > (*binaryTree)->key ) 
			{
				treeInsert(&(*binaryTree)->right, value); //if the new element is greater than the node's key, we go to the right
			}
			else
			{
				contorTree = contorTree + 3; //if-ul: o comparatie si 2 pointeri
				if ( value->key == (*binaryTree)->key )
				{
					treeInsert(&(*binaryTree)->right, value); // if the new element is equal to node's key, we go to the right
				}
			}
		}
	}
}

//am decis sa nu contorizez printarea deoarece ea nu tine de algoritmul de sortare!!
void inorderPrint ( BinaryTree *binaryTree )
{
	if ( NULL != binaryTree )
	{
		inorderPrint ( binaryTree->left );
		printf("%d ", binaryTree->key);
		inorderPrint ( binaryTree->right); 
	}
}

void treeSort ( BinaryTree **binaryTree, BinaryTree * value, int size, int vector[]) 
{//steps for this sorting are very simple: 
 // 1. introduce the values in the binary tree;
 // 2. print the key of the tree's element "inorder".
 // 3. enjoy the sorted vector ;)
	int i;
	for ( i = 0; i < size; i++ )
	{
		
		value = (BinaryTree *)malloc(sizeof(BinaryTree));         contorTree = contorTree + 7; //antetul for-ului alocarea de memorie si atribuirea;
		value->key = vector[i]; 
		treeInsert(binaryTree, value);                            contorTree = contorTree + 1; //apelarea functiei de inserare
	}

	//printf("\nTree Sort:\n");
	//inorderPrint(*binaryTree);

}

