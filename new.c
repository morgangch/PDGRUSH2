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
        raise("Error: class is NULL");
    va_start(ap, class);
    obj = va_new(class, &ap);
    va_end(ap);
    return obj;
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *obj;

    if (!class->__size__ || class->__size__ <= 0)
        raise("Error: class is NULL");
    obj = malloc(class->__size__);
    if (obj == NULL)
        raise("Error: malloc failed");
    obj = memcpy(obj, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(obj, ap);
    return obj;
}

void delete(Object *ptr)
{
    if (ptr == NULL)
        return;

    Class *class = ptr;

    if (class->__dtor__ != NULL)
        class->__dtor__(ptr);
    free(ptr);
}
