#include <stdio.h>
#include <malloc.h>
#include <unistd.h>


#include "algo_api.h"



/* ---------------------------------------------------------------------
 *               LEFT TO RIGHT BREADTH FIRST
 *----------------------------------------------------------------------
 */

//Use queue implemented as linked list to traverse
static void
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








/* --------------------------------------------------------------------- */


tree_node_t  *g_root;


int
main (int argc, char *argv[]) 
{
    int i = 0;
    tree_node_t *n;
    int values[7] = {3,1,4,8,6,9, 2};
    int traverse_type = 1;
    int option, successor,  recursive , inorder , preorder , postorder, breadth;

    successor = recursive = inorder = preorder = postorder = breadth = 0;


    while ((option = getopt(argc, argv, "xipPbS:hT:")) != -1) {
        switch (option) {
            case 'x':
                stack_test();
            break;
            case 'i':
                inorder = 1;
            break;
            case 'p':
                preorder = 1;
            break;
            case 'P':
                postorder = 1;
            break;
            case 'b':
                breadth = 1;
            break;
            case 'S':
                successor = strtol(optarg, NULL, 10);
                traverse_type = SUCCESSOR;
            break;
            case 'T':
                traverse_type = strtol(optarg, NULL, 10);
            break;
            case 'h':
                printf("i - inorder, p - preorder,  P - postorder,  b -breadth  Traverse-Type -T(1/2/3..)\n");
                printf("Traverse-Type : 0 = Recursive 1 = Morris-inorder , 2=Stack-based, 3 = ParentPtr+Visit\n");
                printf("Findsuccessor -S<key>  H-Heapify\n");
                return 0;
            break;
        }
    }

    for (i = 0; i < 7; i++) {
        n = malloc(sizeof(tree_node_t));
        n->value = values[i];
        n->visit = 0;
        n->left = n->right = n->parent = NULL;
        add_node_to_binary_search_tree(n->value, n);
    }
    printf("\n");

    if (inorder) {
        inorder_traverse_or_successor(traverse_type, successor);
        printf("\n");
    } else if (preorder) {
        preorder_traverse_or_successor(traverse_type, successor);
        printf("\n");
    } else if (postorder) {
        postorder_traverse_or_successor(traverse_type, successor);
        printf("\n");
    } else if (breadth) {
        breadth_traverse(g_root);
    }
}

