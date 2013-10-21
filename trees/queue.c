#include <stdio.h>
#include <errno.h>


#include "algo_api.h"

typedef struct _ll_t {
    struct _ll_t *next;
    void         *value;
} ll_t;

static ll_t   *g_head, *g_tail;

int
ll_enqueue(void *n)
{
     ll_t      *l_n;

     l_n = malloc(sizeof(ll_t));
     if (l_n == NULL) {
         return (ENOMEM);
     }
     l_n->next = NULL;
     l_n->value = n;
     if (!g_head) {
         g_head = l_n;
         g_tail = l_n;
     } else {
         g_tail->next = l_n;
         g_tail = l_n;
     }
     return (0);
}

void*
ll_dequeue()
{
     ll_t      *l_n;
     void      *n;

     if (g_head) {
         l_n = g_head->next;
         n = g_head->value;
         free(g_head);
         g_head = l_n;
         return(n);
     } else {
         return(NULL);
     }
}

