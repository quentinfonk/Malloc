/*
** EPITECH PROJECT, 2021
** create
** File description:
** create
*/

#include "../include/my_malloc.h"

int check_struct(size_t size)
{
    if (size == 0)
        return (84);
    return (0);
}

t_alloc *create_nglob(size_t size, t_alloc *c_alloc)
{
    t_alloc *tmp = sbrk(getpagesize());

    while (alloc->next != NULL)
        alloc = alloc->next;
    c_alloc = sbrk(getpagesize());
    c_alloc->next = NULL;
    c_alloc->prev = alloc;
    c_alloc->size = size;
    c_alloc->new_alloc = c_alloc + sizeof(t_alloc);
    c_alloc->empty = NO;
    alloc->next = c_alloc;
    return (c_alloc);
}

t_alloc *create(size_t size, t_alloc *c_alloc)
{
    t_alloc *tmp = sbrk(getpagesize());

    alloc = tmp;
    alloc->next = NULL;
    alloc->prev = NULL;
    alloc->size = size;
    alloc->new_alloc = alloc + sizeof(t_alloc);
    alloc->empty = YES;
    return (c_alloc);
}

char *calloc(size_t nmemb, size_t size)
{
    char *str = malloc(size*nmemb);
    int i = 0;

    for (; i != nmemb*size; i++)
        str[i] = 0;
    str[i] = '\0';
    return (str);
}

void *realloc(void *ptr, size_t size)
{
    void *tmp;

    if (ptr == NULL)
        return (malloc(size));
    if (check_struct(size) == 84) {
        free(ptr);
        return (NULL);
    }
    while (alloc->next != NULL) {
        if (alloc->new_alloc == ptr) {
            if (alloc->size >= size)
                return (alloc->new_alloc);
            else {
                tmp = malloc(size);
                alloc->size = size;
                alloc->new_alloc = tmp;
                free(tmp);
                return (tmp);
            }
        }
        alloc = alloc->next;
    }
    return (NULL);
}
