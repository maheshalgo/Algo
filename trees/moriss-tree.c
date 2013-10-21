#include <stdio.h>
#include <malloc.h>

#include "algo_api.h"


/*
 *     NON RECURSIVE  INORDER TRAVERSAL WITHOUT STACK AND PARENT POINTER
 */


static void
inorder_traverse (tree_node_t *node)
{
    if (node == NULL) return;

    inorder_traverse(node->left);
    printf("%d ", node->value);
    inorder_traverse(node->right);
}


/*
   1. when no left child,  visit node and move to right
   2. Whenever left traversal is needed, transform tree and then go to left child
   3.    TRANFORM done in [2] is
		Make this node right child of rightmost node in left desendant

    THe idea here I think is to thread tree's leaf  nodes.
    Since leaf nodes are pointing to NULL, make the right ptr of 
    leaf node to point to inorder successor [ This is what transform does ]
*/

void
moriss_inorder_tree_traversal (tree_node_t  *rnode)
{
    // rnode is root
    tree_node_t  *node = rnode;
    tree_node_t  *rmost_node = rnode;

    printf("Morris Inorder Tree Traversal\n");
    while (node) {
            if (node->left == NULL) {
	        // when no left child visit node and move to right
                printf("%d ", node->value);
		node = node->right;
            } else {
                rmost_node = node->left;
 	        while (rmost_node->right != NULL && rmost_node->right != node) 
                    rmost_node = rmost_node->right;

	        if (rmost_node->right == node) {
	            // severe right threaded link of this formerly leaf node
		    // visit node and more to right
		    rmost_node->right = NULL;
		    printf("%d ", node->value);
		    node = node->right;
                } else {
	            rmost_node->right = node;
                    node = node->left;
                }
            }
    }
}



