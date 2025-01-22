/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 06
*/

#include "include/my.h"

typedef struct ListNode {
    Object *data;
    struct ListNode *next;
} ListNode;

typedef struct {
    Container base;
    Class *_type;
    size_t _size;
    ListNode *_head;
} ListClass;

typedef struct {
    Iterator base;
    ListClass *_list;
    ListNode *_current;
} ListIteratorClass;

// typedef struct {
//     Container base;
//     Class *_type;
//     size_t _size;
//     Object **_tab;
// } ListClass;

// typedef struct {
//     Iterator base;
//     ListClass *_list;
//     size_t _idx;
// } ListIteratorClass;

static void ListIterator_ctor(ListIteratorClass *this, va_list *args)
{
    this->_list = va_arg(*args, ListClass *);
    this->_idx = va_arg(*args, int);
}

static bool ListIterator_eq(
    ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx == other->_idx);
}

static bool ListIterator_gt(
    ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx > other->_idx);
}

static bool ListIterator_lt(
    ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx < other->_idx);
}

static void ListIterator_incr(ListIteratorClass *this)
{
    this->_idx += 1;
}

static Object *ListIterator_getval(ListIteratorClass *this)
{
    if (this->_idx >= this->_list->_size)
        raise("Out of range");
    return (this->_list->_tab[this->_idx]);
}

static void ListIterator_setval(ListIteratorClass *this, ...)
{
    va_list args;
    Object *new_obj;
    ListClass *list;
    size_t index;

    va_start(args, this);
    list = (ListClass *) this->_list;
    index = this->_idx;

    if (index >= list->_size) {
        va_end(args);
        raise("Index out of bounds");
    }
    new_obj = va_new(list->_type, &args);
    if (!new_obj) {
        va_end(args);
        raise("Out of memory");
    }
    delete (list->_tab[index]);
    list->_tab[index] = new_obj;
    va_end(args);
}

static const ListIteratorClass ListIteratorDescr = {
    {
        /* Iterator struct */
        {
            /* Class struct */
            .__size__ = sizeof(ListIteratorClass),
            .__name__ = "ArrayIterator",
            .__ctor__ = (ctor_t) &ListIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t) &ListIterator_eq,
            .__gt__ = (binary_comparator_t) &ListIterator_gt,
            .__lt__ = (binary_comparator_t) &ListIterator_lt,
        },
        .__incr__ = (incr_t) &ListIterator_incr,
        .__getval__ = (getval_t) &ListIterator_getval,
        .__setval__ = (setval_t) &ListIterator_setval,
    },
    ._list = NULL, ._idx = 0};

static const Class *ListIterator = (const Class *) &ListIteratorDescr;

static void List_ctor(ListClass *this, va_list *args)
{
    size_t size = va_arg(*args, size_t);
    Class *type = va_arg(*args, Class *);
    va_list copy;

    this->_size = size;
    this->_type = type;
    this->_tab = malloc(size * sizeof(Object *));
    if (!this->_tab)
        raise("Out of memory");

    for (size_t i = 0; i < size; i++) {
        va_copy(copy, *args);
        this->_tab[i] = va_new(type, &copy);
        va_end(copy);
        if (!this->_tab[i])
            raise("Out of memory");
    }
}

static void List_dtor(ListClass *this)
{
    for (unsigned int i = 0; i < this->_size; i++)
        delete (this->_tab[i]);
    free(this->_tab);
}

static size_t List_len(ListClass *this)
{
    return (this->_size);
}

static Iterator *List_begin(ListClass *this)
{
    return (new (ListIterator, this, 0));
}

static Iterator *List_end(ListClass *this)
{
    return (new (ListIterator, this, this->_size));
}

static Object *List_getitem(ListClass *this, ...)
{
    va_list args;
    size_t index;

    va_start(args, this);
    index = va_arg(args, size_t);
    va_end(args);

    if (index >= this->_size)
        raise("Index out of bounds");
    return this->_tab[index];
}

static void List_setitem(ListClass *this, ...)
{
    va_list args;
    size_t index;
    Object *new_obj;

    va_start(args, this);
    index = va_arg(args, size_t);
    if (index >= this->_size) {
        va_end(args);
        raise("Index out of bounds");
    }
    new_obj = va_new(this->_type, &args);
    if (!new_obj) {
        va_end(args);
        raise("Out of memory");
    }
    delete (this->_tab[index]);
    this->_tab[index] = new_obj;
    va_end(args);
}

static const ListClass _descr = {
    {
        /* Container struct */
        {
            /* Class struct */
            .__size__ = sizeof(ListClass),
            .__name__ = "Array",
            .__ctor__ = (ctor_t) &List_ctor,
            .__dtor__ = (dtor_t) &List_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t) &List_len,
        .__begin__ = (iter_t) &List_begin,
        .__end__ = (iter_t) &List_end,
        .__getitem__ = (getitem_t) &List_getitem,
        .__setitem__ = (setitem_t) &List_setitem,
    },
    ._type = NULL, ._size = 0, ._tab = NULL};

const Class *List = (const Class *)&_descr;
