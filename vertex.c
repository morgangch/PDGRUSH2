/*
** EPITECH PROJECT, 2025
** Rush2
** File description:
** vertex
*/

#include "include/my.h"

typedef struct
{
    Class   base;
    int     x, d1, d2;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (!args)
        return;
    this->x = va_arg(*args, int);
    this->d1 = va_arg(*args, int);
    this->d2 = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

static char *Vertex_str(VertexClass *this)
{
    char *str;
    int size;

    if (!this)
        return NULL;
    size = snprintf(NULL, 0, "<Vertex (%d, %d, %d)>", this->x, this->d1, this->d2);
    str = (char *)malloc(size + 1);
    if (!str)
        return NULL;
    snprintf(str, size + 1, "<Vertex (%d, %d, %d)>", this->x, this->d1, this->d2);
    return str;
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .d1 = 0,
    .d2 = 0
};

const Class *Vertex = (const Class *)&_description;
