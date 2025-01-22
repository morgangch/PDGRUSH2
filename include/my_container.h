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

typedef struct Container_s My_Container;

typedef Iterator *(*iter_t)(My_Container *this);
typedef size_t (*len_t)(My_Container *this);
typedef Object *(*getitem_t)(My_Container *this, ...);
typedef void (*setitem_t)(My_Container *this, ...);

struct My_Container_s {
    Class       base;
    len_t       __len__;
    iter_t      __begin__;
    iter_t      __end__;
    iter_t      __at__;
    getitem_t   __getitem__;
    setitem_t   __setitem__;
};

#define len(c)          ((Container *)c)->__len__(c)
#define begin(c)        ((Container *)c)->__begin__(c)
#define end(c)          ((Container *)c)->__end__(c)
#define getitem(c, ...) ((Container *)c)->__getitem__(c, __VA_ARGS__)
#define setitem(c, ...) ((Container *)c)->__setitem__(c, __VA_ARGS__)
