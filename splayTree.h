#ifndef SPLAYTREE_H_
#define SPLAYTREE_H_

typedef struct splayTree SplayTree;
struct splayTree
{
	SplayTree* left;
	int key;
	SplayTree* right;
	SplayTree* parent;

} *root;

int contorSplay;

void initSplayTree ( SplayTree ** node );
void leftRotate (SplayTree *node);
void rightRotate (SplayTree *node);
void inorderPrintSplayTree(SplayTree **node);

//implement get root function.

SplayTree* getRoot(SplayTree **node);
void splayTreeInsert(SplayTree **splayTree, SplayTree *parent, SplayTree *value);
void splayCreate( SplayTree *x);
void inorderPrintSplayTree ( SplayTree *splayTree );
void splaySort ( SplayTree **splayTree, int size, int vector[]);


#endif
