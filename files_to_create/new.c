/*
** EPITECH PROJECT, 2025
** Rus02
** File description:
** new.c -> ex01
*/

#include "../include/my.h"

Object *new(const Class *class, ...)
{
    Object *obj = malloc (class->__size__);

    if (obj == NULL)
        raise("Out of memory");
    return (obj);
}

void delete(Object *ptr)
{
    if (ptr != NULL)
        free(ptr);
}
