#include <stdio.h>
#include <malloc.h>
#include <errno.h>

#include "algo_api.h"

static int g_stack_head;

typedef struct _stack_elem {
    void                 *elem;
    struct _stack_elem   *next;
}stack_elem;


int 
stack_push(void *elem)
{
    stack_elem   *e;
  
    e = malloc(sizeof(stack_elem));

    if (e == NULL) {
        return (ENOMEM);
    } else {
        e->elem = elem;
        if (g_stack_head) {
            e->next = g_stack_head;
        } else {
            e->next = NULL;
        }
        g_stack_head = elem;
    }
}

void*
stack_pop()
{
 
    stack_elem   *e;
    void         *elem;

    if (g_stack_head) {
        e = g_stack_head;
        g_stack_head = e->next;
    } else {
        return (NULL);
    }
    elem = e->elem;
    free(e);
    return(elem);
}



