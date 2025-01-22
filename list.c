/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 06
*/

#include "include/my.h"

typedef struct ListClass {
    My_Container base;
    Object *data;
    struct ListClass *next;
} ListClass;

static void List_ctor(ListClass *this, va_list *args)
{
    Object *data;

    if (!args)
        return;
    data = va_arg(*args, Object *);
    this->data = data;
}

static void List_dtor(ListClass *this)
{
    delete(this->data);
    if (this->next)
        delete(this->next);
    free(this->next);
    free(this);
}

static bool List_eq(ListClass *this, ListClass *other)
{
    if (eq(this->data, other->data) == 0)
        return false;
    if (this->next && other->next)
        return eq(this->next, other->next);
    if (!this->next && !other->next)
        return true;
    return false;
}

static size_t List_len(ListClass *this)
{
    if (!this)
        return 0;
    return 1 + List_len(this->next);
}

static Object *List_getitem(ListClass *this, ...)
{
    va_list args;
    size_t index;

    va_start(args, this);
    index = va_arg(args, size_t);
    va_end(args);

    if (index == 0)
        return this->data;
    if (this->next)
        return List_getitem(this->next, index - 1);
    raise("Index out of bounds");
    return NULL;
}

static Object *List_begin(ListClass *this)
{
    return this->data;
}

static Object *List_end(ListClass *this)
{
    if (this->next)
        return List_end(this->next);
    return this->data;
}

static void List_additem_front(ListClass *this, ...)
{
    va_list args;
    Object *data;
    ListClass *new_node;

    va_start(args, this);
    data = va_arg(args, Object *);
    va_end(args);

    new_node = malloc(sizeof(ListClass));
    if (!new_node)
        raise("Out of memory");
    new_node->data = this->data;
    new_node->next = this->next;
    this->data = data;
    this->next = new_node;
}

static void List_additem_at(ListClass *this, ...)
{
    va_list args;
    size_t index;
    Object *data;

    va_start(args, this);
    index = va_arg(args, size_t);
    data = va_arg(args, Object *);
    va_end(args);

    if (index == 0) {
        List_additem_front(this, data);
        return;
    }
    if (this->next)
        List_additem_at(this->next, index - 1, data);
    else
        raise("Index out of bounds");
}


static void List_additem_back(ListClass *this, ...)
{
    va_list args;
    Object *data;
    ListClass *new_node;

    va_start(args, this);
    data = va_arg(args, Object *);
    va_end(args);

    if (this->next)
        List_additem_back(this->next, data);
    else {
        new_node = malloc(sizeof(ListClass));
        if (!new_node)
            raise("Out of memory");
        new_node->data = data;
        new_node->next = NULL;
        this->next = new_node;
    }
}

static void List_popback(ListClass *this)
{
    if (this->next->next)
        List_popback(this->next);
    else {
        List_dtor(this->next);
        this->next = NULL;
    }
}

static void List_popfront(ListClass *this)
{
    delete(this->data);
    this = this->next;
}

static void List_erase(ListClass *this, ...)
{
    va_list args;
    size_t index;

    va_start(args, this);
    index = va_arg(args, size_t);
    if (index == 0) {
        List_popfront(this);
    } else if (this->next)
        List_erase(this->next, index - 1);
    else
        raise("Index out of bounds");
    va_end(args);
}

static const ListClass _description = {
    {
        {
            /* Class struct */
            .__size__ = sizeof(ListClass),
            .__name__ = "List",
            .__ctor__ = (ctor_t) &List_ctor,
            .__dtor__ = (dtor_t) &List_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&List_eq,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (l_len_t) &List_len,
        .__begin__ = (l_getitem_t) &List_begin,
        .__end__ = (l_getitem_t) &List_end,
        .__at__ = (l_getitem_t) &List_getitem,
        .__setitem__ = (l_setitem_t) &List_additem_at,
        .__pushback__ = (l_setitem_t) &List_additem_back,
        .__pushfront__ = (l_setitem_t) &List_additem_front,
        .__popback__ = (l_dellitem_t) &List_popback,
        .__popfront__ = (l_dellitem_t) &List_popfront,
        .__erase__ = (l_dellitem_t) &List_erase
    },
    .data = NULL,
    .next = NULL
};

const Class *List = (const Class *)&_description;
