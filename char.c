/*
** EPITECH PROJECT, 2025
** Rush2
** File description:
** Char
*/

#include "include/my.h"

/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Evalueercice 02
*/

#include "include/my.h"

typedef struct
{
    Class   base;
    char     value;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (!args)
        return;
    this->value = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

static char *Char_str(CharClass *this)
{
    char *str;
    int size;

    if (!this)
        return NULL;
    size = snprintf(NULL, 0, "<Char (%c)>", this->value);
    str = (char *)malloc(size + 1);
    if (!str)
        return NULL;
    snprintf(str, size + 1, "<Char (%c)>", this->value);
    return str;
}

static Object *Char_add(const CharClass *this, const CharClass *other)
{
    return new(Char, this->value + other->value);
}

static Object *Char_sub(const CharClass *this, const CharClass *other)
{
    return new(Char, this->value - other->value);
}

static Object *Char_mul(const CharClass *this, const CharClass *other)
{
    return new(Char, this->value * other->value);
}

static Object *Char_div(const CharClass *this, const CharClass *other)
{
    return new(Char, this->value / other->value);
}

static bool Char_eq(const CharClass *this, const CharClass *other)
{
    return this->value == other->value;
}

static bool Char_gt(const CharClass *this, const CharClass *other)
{
    return this->value > other->value;
}

static bool Char_lt(const CharClass *this, const CharClass *other)
{
    return this->value < other->value;
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .value = 0,
};

const Class   *Char = (const Class *)&_description;
