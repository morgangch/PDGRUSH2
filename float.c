/*
** EPITECH PROJECT, 2025
** Rush2
** File description:
** float
*/

#include "include/my.h"

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
    float     value;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (!args)
        return;
    this->value = va_arg(*args, int);
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

static char *Float_str(FloatClass *this)
{
    char *str;
    int size;

    if (!this)
        return NULL;
    size = snprintf(NULL, 0, "<Float (%c)>", this->value);
    str = (char *)malloc(size + 1);
    if (!str)
        return NULL;
    snprintf(str, size + 1, "<Float (%c)>", this->value);
    return str;
}

static Object *Float_add(const FloatClass *this, const FloatClass *other)
{
    return new(Float, this->value + other->value);
}

static Object *Float_sub(const FloatClass *this, const FloatClass *other)
{
    return new(Float, this->value - other->value);
}

static Object *Float_mul(const FloatClass *this, const FloatClass *other)
{
    return new(Float, this->value * other->value);
}

static Object *Float_div(const FloatClass *this, const FloatClass *other)
{
    return new(Float, this->value / other->value);
}

static bool Float_eq(const FloatClass *this, const FloatClass *other)
{
    return this->value == other->value;
}

static bool Float_gt(const FloatClass *this, const FloatClass *other)
{
    return this->value > other->value;
}

static bool Float_lt(const FloatClass *this, const FloatClass *other)
{
    return this->value < other->value;
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .value = 0,
};

const Class   *Float = (const Class *)&_description;
