/*
** EPITECH PROJECT, 2021
** my_malloc
** File description:
** my_malloc
*/

#include <stddef.h>
#include "../include/my_malloc.h"

enum empt check_space(size_t size)
{
    for (int i = 0; alloc->next != NULL; i++) {
        if (alloc->size >= size && alloc->empty == YES)
            return (YES);
        alloc = alloc->next;
    }
    return (NO);
}

void *free_space(size_t size)
{
    t_alloc *alloc_tmp = NULL;
    void *tmp;

    for (int i = 0; alloc->next != NULL; i++) {
        if (alloc->size >= size && alloc->empty == YES)
            alloc->empty = NO;
        alloc = alloc->next;
    }
    while (alloc->prev != NULL)
        alloc = alloc->prev;
    tmp = malloc(size);
    return (tmp);
}

void *add_node(size_t size)
{
    t_alloc *alloc_tmp = NULL;

    if (check_space(size) == YES)
        return (free_space(size));
    alloc_tmp = create_nglob(size, alloc_tmp);
    while (alloc->prev != NULL)
        alloc = alloc->prev;
    return (alloc_tmp->new_alloc);
}

void *malloc(size_t size)
{
    if (check_struct(size) == 84)
        return (NULL);
    if (alloc == NULL) {
        create(size, NULL);
        return (alloc->new_alloc);
    }
    while (alloc->prev != NULL)
        alloc = alloc->prev;
    return (add_node(size));
}

void free(void *tmp)
{
    while (alloc != NULL) {
        if (tmp == alloc->new_alloc) {
            alloc->empty = YES;
            alloc->new_alloc = memset(alloc->new_alloc, 0, alloc->size);
            return;
        }
        alloc = alloc->next;
    }    
    return;
}
