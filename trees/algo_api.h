#include <stdio.h>


#ifndef __ALGO_API__
#define __ALGO_API__

typedef struct _tree_node {
    struct _tree_node *left;
    struct _tree_node *right;
    struct _tree_node *parent;
    int           visit;
    int           value;
} tree_node_t;


extern tree_node_t  *g_root;


int ll_enqueue(void *n);
void *ll_dequeue();

void  add_node_to_binary_search_tree(int value, tree_node_t *node);
void  moriss_inorder_tree_traversal (tree_node_t  *rnode);

void* stack_pop();
int   stack_push(void *elem);

#endif


