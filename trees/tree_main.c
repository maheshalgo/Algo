#include <stdio.h>
#include <malloc.h>

#include "algo_api.h"


tree_node_t  *g_root;

#if 0
int
main (int argc, char *argv[])
{
    int i = 0;
    tree_node_t *n;
    int values[7] = {3,1,4,8,6,9, 2};
    int traversal = 1;
    int option, successor,  recursive , inorder , preorder , postorder, breadth;

    successor = recursive = inorder = preorder = postorder = breadth = 0;


    while ((option = getopt(argc, argv, "RipobS:h")) != -1) {
        switch (option) {
            case 'R':
                recursive = 1;
            break;
            case 'i':
                inorder = 1;
            break;
            case 'p':
                preorder = 1;
            break;
            case 'o':
                postorder = 1;
            break;
            case 'b':
                breadth = 1;
            break;
            case 'S':
                successor = strtol(optarg, NULL, 10);
                traversal = 0;
            break;
            case 'h':
                printf("R recursive, i inorder, p preorder,  o postorder,  b breadth\n");
                return 0;
            break;
        }
    }

    for (i = 0; i < 7; i++) {
        n = malloc(sizeof(tree_node_t));
        n->value = values[i];
        n->visit = 0;
        n->left = n->right = n->parent = NULL;
        add_tree_node_to_binary_search_tree(n->value, n);
    }
    printf("\n");

    if (inorder) {
        inorder_traverse_or_successor(traversal, recursive, successor);
        printf("\n");
    }
    if (breadth) breadth_traverse(g_root);
}
#endif

int
main () 
{
    int i = 0;
    tree_node_t *n;
    //int values[7] = {3,1,4,8,6,9, 2};
    int values[7] = {10, 5, 20, 3, 7};

    //for (i = 0; i < 7; i++) {
    for (i = 0; i < 5; i++) {
        n = malloc(sizeof(tree_node_t));
        n->value = values[i];
        n->left = n->right = n->parent = NULL;
        add_node_to_binary_search_tree(n->value, n);
    }

    //non_recur_inorder(g_root);
    inorder_traverse(g_root);
    printf("\n");
    moriss_inorder_tree_traversal(g_root);
    printf("\n");
}

