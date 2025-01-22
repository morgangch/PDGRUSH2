/*
** EPITECH PROJECT, 2025
** PDGRUSH2
** File description:
** test_new
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

Test(new, test_new)
{
    Object  *array = new(Array, 10, Int, 0);
    Object  *it = begin(array);
    Object  *it_end = end(array);

    cr_assert_not_null(array);
    cr_assert_not_null(it);
    cr_assert_not_null(it_end);
    cr_assert_eq(len(array), 10);
    setitem(array, 5, 12);
    setitem(array, 6, 13);
    delete(it);
    delete(it_end);
    delete(array);
}

Test(new, test_newplayer)
{
    Object  *player = new(Player, "player");

    cr_assert_not_null(player);
    delete(player);
}

Test(new, test_newarray)
{
    Object  *array = new(Array, 10, Int, 0);
    Object  *it = begin(array);
    Object  *it_end = end(array);

    cr_assert_not_null(array);
    cr_assert_not_null(it);
    cr_assert_not_null(it_end);
    cr_assert_eq(len(array), 10);
    setitem(array, 5, 12);
    setitem(array, 6, 13);
    delete(it);
    delete(it_end);
    delete(array);
}

Test(new, test_newint)
{
    Object  *integer = new(Int, 12);

    cr_assert_not_null(integer);
    cr_assert_str_eq(str(integer), "<Int (12)>");
    delete(integer);
}

Test(new, test_newchar)
{
    Object  *character = new(Char, 'c');

    cr_assert_not_null(character);
    cr_assert_str_eq(str(character), "<Char (c)>");
    delete(character);
}

Test(new, test_newfloat)
{
    Object  *floating = new(Float, 12.34);

    cr_assert_not_null(floating);
    cr_assert_str_eq(str(floating), "<Float (12.340000)>");
    delete(floating);
}

Test(new, test_newpoint)
{
    Object  *point = new(Point, 12, 34);

    cr_assert_not_null(point);
    cr_assert_str_eq(str(point), "<Point (12, 34)>");
    delete(point);
}

Test(new, test_newvertex)
{
    Object  *vertex = new(Vertex, 12, 34, 56);

    cr_assert_not_null(vertex);
    cr_assert_str_eq(str(vertex), "<Vertex (12, 34, 56)>");
    delete(vertex);
}
