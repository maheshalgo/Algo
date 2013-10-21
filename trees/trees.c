#include <stdio.h>
#include <malloc.h>
#include <unistd.h>


#include "algo_api.h"

enum {
    RECURSIVE = 0,
    MORRIS,
    STACK_BASED,
    PARENT_PTR_VISIT_FLAG,

    // keep it last
    SUCCESSOR 
};


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






/* ---------------------------------------------------------------------
 *               PRE ORDER
 *----------------------------------------------------------------------
 */
void
non_recur_preorder_with_visit_flag(tree_node_t *node)
{
    tree_node_t        *n;
    n = node;
    
    printf("Preorder Traversal Using Parent Pointer and Visit Flag in Non-Recursive\n");

    n = node;
    printf("%d ", node->value);
    while(n) {
        if (n->left && !((n->left)->visit)) {
            n = n->left;
            printf("%d ", n->value);
        } else if (n->right && !((n->right)->visit)) {
            n = n->right;
            printf("%d ", n->value);
        } else {
            n->visit = 1;
            n = n->parent;
        }
    }
}


/* ---------------------------------------------------------------------
 *               POST ORDER
 *----------------------------------------------------------------------
 */





/* --------------------------------------------------------------------- */
static void
inorder_traverse_or_successor(int traversal_type, int successor)
{

    switch(traversal_type) {
        case RECURSIVE : 
            printf("Recursive Inorder Traversal\n");
            inorder_r_traverse(g_root);
        break;
        case STACK_BASED: 
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

static void
preorder_traverse_or_successor(int traversal_type, int successor)
{

}

static void
postorder_traverse_or_successor(int traversal_type, int successor)
{

}

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


    while ((option = getopt(argc, argv, "ipPbS:hT:")) != -1) {
        switch (option) {
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

