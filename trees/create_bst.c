#include <stdio.h>
#include <malloc.h>

#include "algo_api.h"

extern tree_node_t  *g_root;

/*
 *     NON RECURSIVE  INORDER TRAVERSAL WITHOUT STACK AND PARENT POINTER
 */


void
add_node_to_binary_search_tree(int value, tree_node_t *node)
{
    tree_node_t     *n;

    if (g_root) {
        n = g_root;
        while(n) {
            if (n->value < value) {
                // insert on right subtree
                if (n->right) {
                    n = n->right;
                } else {
                    n->right = node;
                    node->parent = n;
                    printf("added %d to right of %d\n", value, n->value);
                    break;
                }
            } else {
                // insert on left
                if (n->left) {
                    n = n->left;
                } else {
                    n->left = node;
                    node->parent = n;
                    printf("added %d to left of %d\n", value, n->value);
                    break;
                }
            }
        }
    } else {
        g_root = node;
        printf("added as root\n", value);
    }
}

