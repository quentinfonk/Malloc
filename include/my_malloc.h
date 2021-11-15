/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#ifndef MY_MALLOC_H
#define MY_MALLOC_H

#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

enum empt {YES, NO};

typedef struct s_alloc t_alloc;
struct s_alloc
{
    t_alloc *next;
    t_alloc *prev;
    size_t size;
    void *new_alloc;
    bool empty;
};

static t_alloc *alloc = NULL;

void *malloc(size_t size);
void free(void *tmp);
char *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *free_space(size_t size);
enum empt check_space(size_t size);
int check_struct(size_t size);
t_alloc *create_nglob(size_t size, t_alloc *c_alloc);
t_alloc *create(size_t size, t_alloc *c_alloc);

#endif
