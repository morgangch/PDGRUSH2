/*
** EPITECH PROJECT, 2025
** Rus02
** File description:
** new.c -> ex01
*/

#include "include/my.h"

Object *new(const Class *class, ...)
{
    Object *obj;
    va_list ap;

    if (!class->__size__ || class->__size__ <= 0)
        raise("Error: size is NULL");
    obj = malloc(class->__size__);
    if (obj == NULL)
        raise("Error: malloc failed");
    if (class->__ctor__ != NULL) {
        va_start(ap, class);
        class->__ctor__(obj, &ap);
        va_end(ap);
    }
    return (obj);
}

void delete(Object *ptr)
{
    if (ptr != NULL)
        free(ptr);
}
