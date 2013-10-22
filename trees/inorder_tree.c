#include <stdio.h>
#include <malloc.h>
#include <unistd.h>


#include "algo_api.h"



/* ---------------------------------------------------------------------
 *               INORDER
 *----------------------------------------------------------------------
 */

static void
inorder_r_traverse (tree_node_t *node)
{
    if (node == NULL) return;

    inorder_r_traverse(node->left);
    printf("%d ", node->value);
    inorder_r_traverse(node->right);
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

    printf("Inorder Traversal Using Parent Pointer Only and Non-Recursive\n");
    
    while (n) {
       if (n->left) {
           n = n->left;
       } else {
rightsub: 
          if (n) printf("%d ", n->value);
          if (n && n->right) {
              // before moving to right set parent pointer of node on right to
              // unprocessed inorder node
              // which will be this node's parent
              tnode = n;
              n = n->right;
              if (n) n->parent = tnode->parent;
          } else {
              if (n) {
                  n = n->parent;
                  goto rightsub;
              }
          }
       }
    }

/*
    // Since parent pointers are messed up, walk from root and setup parent correctly
    // Infact only parent pointer of right child nodes are messed... correct only them
    n = node; // root
    node->parent = NULL;
    n = n->left;
    while (n != node) {
        if (n->left) {
            n = n->left;
        } else {
            if (n->right) {
                tnode = n;
                n = n->right;
                n->parent = tnode;
            } else {
                n = n->parent;
                // need to walk right sub
            }
        }
    }
*/
}


static void
non_recur_inorder_with_visit_flag(tree_node_t *node)
{
    tree_node_t        *n;
    n = node;

    printf("Inorder Traversal Using Parent Pointer and Visit Flag in Non-Recursive\n");

    while(n) {
        if (n->left &&
            !((n->left)->visit)) {
                n = n->left;
        } else {
           if (!n->visit) {
               printf("%d ", n->value);
               n->visit = 1;
           }
           if (n->right && !(n->right)->visit) {
                n = n->right;
           } else {
                n = n->parent;
           }
        }
    }
}


static void
inorder_stack_based(tree_node_t *node)
{
    tree_node_t       *n = node;
    tree_node_t       *remove_n;

    printf("Inorder Non recursive Traversal Using stack\n");

    while(n) {
        if (n->left) {
            stack_push(n);
            n = n->left;
        } else {
rightsub:
            if (n->right) {
                printf("%d ", n->value);
                n = n->right;
            } else {
                printf("%d ", n->value);
                n = stack_pop();
                if (n) goto rightsub;
            }
        }
    }
    printf("\n");
}




/* --------------------------------------------------------------------- */

void
inorder_traverse_or_successor(int traversal_type, int successor)
{

    switch(traversal_type) {
        case RECURSIVE : 
            printf("Recursive Inorder Traversal\n");
            inorder_r_traverse(g_root);
        break;
        case STACK_BASED: 
            inorder_stack_based(g_root);
        break;
        case MORRIS: 
             moriss_inorder_tree_traversal(g_root);
        break;
        case PARENT_PTR_VISIT_FLAG: 
             non_recur_inorder_with_visit_flag(g_root);
        break;
        case SUCCESSOR: 
        // find sucessor of key
        //key = successor;
        break;
        //non_recur_inorder_with_parent_ptr_changed(node); // Tree Destructive....
    }
}

