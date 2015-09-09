#ifndef BTREE_H_
#define BTREE_H_

typedef struct binaryTree BinaryTree;
struct binaryTree
{
	BinaryTree *left;
	int key;
	BinaryTree *right;
};
	
int contorTree;
void treeInsert( BinaryTree **binaryTree, BinaryTree *value );
void inorderPrint ( BinaryTree *binaryTree );
void treeSort ( BinaryTree **binaryTree, BinaryTree * value, int size, int vector[]);
	
#endif