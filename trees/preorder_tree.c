#include <stdio.h>
#include <malloc.h>
#include <unistd.h>


#include "algo_api.h"



/* ---------------------------------------------------------------------
 *               PRE ORDER TRAVERSAL ALGOs
 *----------------------------------------------------------------------
 */

static void
preorder_r_traverse (tree_node_t *node)
{
    if (node == NULL) return;

    printf("%d ", node->value);
    preorder_r_traverse(node->left);
    preorder_r_traverse(node->right);
}


// Logic here is that if node has right sub tree, 
// and after left sub tree is visited, and its time to
// traverse right sub tree, before moving to right sub tree,
// set the parent of right sub tree node to this node's parent.
//     a
//   b    c
// d   e
//   In this case after visiting d, b and its turn to visit tree rooted by 'e'
//   set parent of 'e' to same as parent of 'b'
//   basically node that needs to be visited after visiting tree rooted at 'e'

static void
non_recur_inorder_with_parent_ptr_changed(tree_node_t *node)
{
    tree_node_t   *n = node;
    tree_node_t   *tnode;

    printf("Preorder Traversal Using Parent Pointer Only and Non-Recursive\n");
    
}


static void
non_recur_preorder_with_visit_flag(tree_node_t *node)
{
    tree_node_t        *n;
    n = node;

    printf("Preorder Traversal Using Parent Pointer and Visit Flag in Non-Recursive\n");

    while(n) {
        if (!n->visit) {
            printf("%d ", n->value);
            n->visit = 1;
        }
        if (n->left &&
            !((n->left)->visit)) {
                n = n->left;
        } else {
           if (n->right && !(n->right)->visit) {
                n = n->right;
           } else {
                n = n->parent;
           }
        }
    }
}

static void
non_recur_preorder_with_stack(tree_node_t *node)
{
    tree_node_t        *n;
    n = node;

    printf("Non Recur Preorder Traversal Using Stack\n");

    while (n) {
        printf ("%d ", n->value);
        if (n->right) {
            stack_push(n->right);
        }
        if (n->left) {
            n = n->left;
        } else {
            n = stack_pop();
        }
    }
}



/* --------------------------------------------------------------------- */

void
preorder_traverse_or_successor(int traversal_type, int successor)
{

    switch(traversal_type) {
        case RECURSIVE : 
            printf("Recursive Inorder Traversal\n");
            preorder_r_traverse(g_root);
        break;
        case STACK_BASED: 
             non_recur_preorder_with_stack(g_root);
        break;
        case MORRIS: 
             //moriss_inorder_tree_traversal(g_root);
        break;
        case PARENT_PTR_VISIT_FLAG: 
             non_recur_preorder_with_visit_flag(g_root);
        break;
        case SUCCESSOR: 
        // find sucessor of key
        //key = successor;
        break;
    }
}

