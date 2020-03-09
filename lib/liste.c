#include "liste.h"

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

node* l_make_node(void* data)
{
    return NULL;
}

void l_free_node(node* n)
{
    return;
}

void l_free_list(node* n)
{
    return;
}

int l_length(node const* n)
{
    return 0;
}

node* l_head(node* n)
{
    return NULL;
}

node* l_tail(node* n)
{
    return NULL;
}

node* l_skip(node* n, int i)
{
    return NULL;
}

node* l_append(node** p, node* tail)
{
    assert(p);
    return NULL;
}

node* l_prepend(node** p, node* head)
{
    assert(p);
    return NULL;
}

node* l_insert(node** p, node* body)
{
    assert(p);
    return NULL;
}

node* l_remove(node* n)
{
    return NULL;
}
