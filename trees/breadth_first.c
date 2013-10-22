#include <stdio.h>
#include <malloc.h>
#include <unistd.h>


#include "algo_api.h"



/* ---------------------------------------------------------------------
 *               LEFT TO RIGHT BREADTH FIRST
 *----------------------------------------------------------------------
 */

//Use queue implemented as linked list to traverse
void
breadth_traverse (tree_node_t *node)
{
    tree_node_t       *n;

    printf("Breadth First Traversal using queues implemented as link list\n");

    if (node) {
        ll_enqueue(node);
    }
    n = node;
    while (n) {
        n = ll_dequeue();
        if (n) {
            printf("%d ", n->value);
            if (n->left) {
                ll_enqueue(n->left);
            }
            if (n->right) {
                ll_enqueue(n->right);
            }
        }
    }    
    printf("\n");
}








