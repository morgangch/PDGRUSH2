/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "include/point.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (!args)
        return;
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

static char *Point_str(PointClass *this)
{
    char *str;
    int size;

    if (!this)
        return NULL;
    size = snprintf(NULL, 0, "<Point (%d, %d)>", this->x, this->y);
    str = (char *)malloc(size + 1);
    if (!str)
        return NULL;
    snprintf(str, size + 1, "<Point (%d, %d)>", this->x, this->y);
    return str;
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = NULL,    /* Implement this method for exercice 03 */
        .__sub__ = NULL,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
