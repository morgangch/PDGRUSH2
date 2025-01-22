/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 05
*/

#pragma once

#include "object.h"
#include "iterator.h"
#include "raise.h"

typedef struct My_Container_s My_Container;

typedef Iterator *(*l_iter_t)(My_Container *this);
typedef size_t (*l_len_t)(My_Container *this);
typedef Object *(*l_getitem_t)(My_Container *this, ...);
typedef void (*l_setitem_t)(My_Container *this, ...);
typedef void (*l_dellitem_t)(My_Container *this, ...);

struct My_Container_s {
    Class       base;
    l_len_t       __len__;
    l_getitem_t      __begin__;
    l_getitem_t      __end__;
    l_getitem_t     __at__ ;
    l_setitem_t   __setitem__;
    l_setitem_t  __pushback__;
    l_setitem_t   __pushfront__;
    l_dellitem_t   __popback__;
    l_dellitem_t   __popfront__;
    l_dellitem_t  __erase__;
};

#define l_len(c)          ((My_Container *)c)->__len__(c)
#define l_begin(c)        ((My_Container *)c)->__begin__(c)
#define l_end(c)          ((My_Container *)c)->__end__(c)
#define l_getitem(c, ...) ((My_Container *)c)->__at__(c, __VA_ARGS__)
#define l_setitem(c, ...) ((My_Container *)c)->__setitem__(c, __VA_ARGS__)
#define l_pushback(c, ...) ((My_Container *)c)->__pushback__(c, __VA_ARGS__)
#define l_pushfront(c, ...) ((My_Container *)c)->__pushfront__(c, __VA_ARGS__)
#define l_popback(c) ((My_Container *)c)->__popback__(c)
#define l_popfront(c) ((My_Container *)c)->__popfront__(c)
#define l_erase(c, ...) ((My_Container *)c)->__erase__(c, __VA_ARGS__)