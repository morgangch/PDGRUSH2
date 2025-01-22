/*
** EPITECH PROJECT, 2025
** Rush2
** File description:
** int
*/

#include "include/my.h"

typedef struct
{
    Class   base;
    int     value;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (!args)
        return;
    this->value = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

static char *Int_str(IntClass *this)
{
    char *str;
    int size;

    if (!this)
        return NULL;
    size = snprintf(NULL, 0, "<Int (%d)>", this->value);
    str = (char *)malloc(size + 1);
    if (!str)
        return NULL;
    snprintf(str, size + 1, "<Int (%d)>", this->value);
    return str;
}

static Object *Int_add(const IntClass *this, const IntClass *other)
{
    return new(Int, this->value + other->value);
}

static Object *Int_sub(const IntClass *this, const IntClass *other)
{
    return new(Int, this->value - other->value);
}

static Object *Int_mul(const IntClass *this, const IntClass *other)
{
    return new(Int, this->value * other->value);
}

static Object *Int_div(const IntClass *this, const IntClass *other)
{
    return new(Int, this->value / other->value);
}

static bool Int_eq(const IntClass *this, const IntClass *other)
{
    return this->value == other->value;
}

static bool Int_gt(const IntClass *this, const IntClass *other)
{
    return this->value > other->value;
}

static bool Int_lt(const IntClass *this, const IntClass *other)
{
    return this->value < other->value;
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .value = 0,
};

const Class   *Int = (const Class *)&_description;
