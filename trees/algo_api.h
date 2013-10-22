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

enum {
    RECURSIVE = 0,
    MORRIS,
    STACK_BASED,
    PARENT_PTR_VISIT_FLAG,

    // keep it last
    SUCCESSOR
};


extern tree_node_t  *g_root;


int ll_enqueue(void *n);
void *ll_dequeue();
void stack_test ();

void  add_node_to_binary_search_tree(int value, tree_node_t *node);
void  moriss_inorder_tree_traversal (tree_node_t  *rnode);
void  inorder_traverse_or_successor(int traversal_type, int successor);
void  preorder_traverse_or_successor(int traversal_type, int successor);
void  postorder_traverse_or_successor(int traversal_type, int successor);


void* stack_pop();
int   stack_push(void *elem);

#endif


