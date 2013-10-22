#include <stdio.h>
#include <malloc.h>
#include <unistd.h>


#include "algo_api.h"



/* ---------------------------------------------------------------------
 *               POST ORDER TRAVERSAL ALGOs...
 *----------------------------------------------------------------------
 */

static void
postorder_r_traverse (tree_node_t *node)
{
    if (node == NULL) return;

    postorder_r_traverse(node->left);
    postorder_r_traverse(node->right);
    printf("%d ", node->value);
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

    printf("Postorder Traversal Using Parent Pointer Only and Non-Recursive\n");
    
}


static void
non_recur_postorder_with_visit_flag(tree_node_t *node)
{
    tree_node_t        *n;
    n = node;

    printf("Postorder Traversal Using Parent Pointer and Visit Flag in Non-Recursive\n");

    while(n) {
        if (n->left &&
            !((n->left)->visit)) {
                n = n->left;
        } else {
           if (n->right && !(n->right)->visit) {
                n = n->right;
           } else {
               if (!n->visit) {
                   printf("%d ", n->value);
                   n->visit = 1;
               }
               n = n->parent;
           }
        }
    }
}

static void
non_recur_postorder_using_stack (tree_node_t *node)
{
    tree_node_t            *n = node;

    while (n) {
        if (n->left || n->right) {
            if (n->left && n->left != p) {
                stack_push(n);
                n = n->left;
            } else {
                n = n->right;
            }
        } else {
           printf("%d ", n->value);
           p = stack_pop();
           if (p && p->right && p->right != n) {
               stack_push(n);
               n = n->right;
           } else if (p && p->right && p->right == n) {
               printf("%d ", p->value);
               n = stack_pop();
           }
        }
    }
}





/* --------------------------------------------------------------------- */

void
postorder_traverse_or_successor(int traversal_type, int successor)
{

    switch(traversal_type) {
        case RECURSIVE : 
            printf("Recursive Postorder Traversal\n");
            postorder_r_traverse(g_root);
        break;
        case STACK_BASED: 
        break;
        case MORRIS: 
             //moriss_inorder_tree_traversal(g_root);
        break;
        case PARENT_PTR_VISIT_FLAG: 
             non_recur_postorder_with_visit_flag(g_root);
        break;
        case SUCCESSOR: 
        // find sucessor of key
        //key = successor;
        break;
    }
}

