/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include "include/my.h"

typedef struct {
    Container base;
    Class *_type;
    size_t _size;
    Object **_tab;
} ArrayClass;

typedef struct {
    Iterator base;
    ArrayClass *_array;
    size_t _idx;
} ArrayIteratorClass;

static void ArrayIterator_ctor(ArrayIteratorClass *this, va_list *args)
{
    this->_array = va_arg(*args, ArrayClass *);
    this->_idx = va_arg(*args, int);
}

static bool ArrayIterator_eq(
    ArrayIteratorClass *this, ArrayIteratorClass *other)
{
    return (this->_idx == other->_idx);
}

static bool ArrayIterator_gt(
    ArrayIteratorClass *this, ArrayIteratorClass *other)
{
    return (this->_idx > other->_idx);
}

static bool ArrayIterator_lt(
    ArrayIteratorClass *this, ArrayIteratorClass *other)
{
    return (this->_idx < other->_idx);
}

static void ArrayIterator_incr(ArrayIteratorClass *this)
{
    this->_idx += 1;
}

static Object *ArrayIterator_getval(ArrayIteratorClass *this)
{
    if (this->_idx >= this->_array->_size)
        raise("Out of range");
    return (this->_array->_tab[this->_idx]);
}

static void ArrayIterator_setval(ArrayIteratorClass *this, ...)
{
    va_list args;
    Object *new_obj;
    ArrayClass *array;
    size_t index;

    array = (ArrayClass *) this->_array;
    index = this->_idx;
    if (index >= array->_size)
        raise("Index out of bounds");
    va_start(args, this);
    new_obj = va_new(array->_type, &args);
    delete (array->_tab[index]);
    array->_tab[index] = new_obj;
    va_end(args);
}

static const ArrayIteratorClass ArrayIteratorDescr = {
    {
        /* Iterator struct */
        {
            /* Class struct */
            .__size__ = sizeof(ArrayIteratorClass),
            .__name__ = "ArrayIterator",
            .__ctor__ = (ctor_t)&ArrayIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ArrayIterator_eq,
            .__gt__ = (binary_comparator_t)&ArrayIterator_gt,
            .__lt__ = (binary_comparator_t)&ArrayIterator_lt,
        },
        .__incr__ = (incr_t)&ArrayIterator_incr,
        .__getval__ = (getval_t)&ArrayIterator_getval,
        .__setval__ = (setval_t)&ArrayIterator_setval,
    },
    ._array = NULL,
    ._idx = 0
};

static const Class *ArrayIterator = (const Class *) &ArrayIteratorDescr;

static void Array_ctor(ArrayClass *this, va_list *args)
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
    }
}

static void Array_dtor(ArrayClass *this)
{
    for (unsigned int i = 0; i < this->_size; i++)
        delete (this->_tab[i]);
    free(this->_tab);
}

static size_t Array_len(ArrayClass *this)
{
    return (this->_size);
}

static Iterator *Array_begin(ArrayClass *this)
{
    return (new(ArrayIterator, this, 0));
}

static Iterator *Array_end(ArrayClass *this)
{
    return (new(ArrayIterator, this, this->_size));
}

static Object *Array_getitem(ArrayClass *this, ...)
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

static void Array_setitem(ArrayClass *this, ...)
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
    va_end(args);
    delete (this->_tab[index]);
    this->_tab[index] = new_obj;
}

static const ArrayClass _descr = {
    {
        /* Container struct */
        {
            /* Class struct */
            .__size__ = sizeof(ArrayClass),
            .__name__ = "Array",
            .__ctor__ = (ctor_t) &Array_ctor,
            .__dtor__ = (dtor_t) &Array_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t) &Array_len,
        .__begin__ = (iter_t) &Array_begin,
        .__end__ = (iter_t) &Array_end,
        .__getitem__ = (getitem_t) &Array_getitem,
        .__setitem__ = (setitem_t) &Array_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._tab = NULL
};

const Class *Array = (const Class *) &_descr;
