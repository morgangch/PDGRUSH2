/*
** EPITECH PROJECT, 2025
** PDGRUSH2
** File description:
** test_new
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

Test(new, test_new)
{
    Object *array = new (Array, 10, Int, 0);
    Object *it = begin(array);
    Object *it_end = end(array);

    cr_assert_not_null(array);
    cr_assert_not_null(it);
    cr_assert_not_null(it_end);
    cr_assert_eq(len(array), 10);
    setitem(array, 5, 12);
    setitem(array, 6, 13);
    delete (it);
    delete (it_end);
    delete (array);
}

Test(new, test_newplayer)
{
    Object *player = new (Player, "player");

    cr_assert_not_null(player);
    delete (player);
}

Test(new, test_newarray)
{
    Object *array = new (Array, 10, Int, 0);
    Object *it = begin(array);
    Object *it_end = end(array);

    cr_assert_not_null(array);
    cr_assert_not_null(it);
    cr_assert_not_null(it_end);
    cr_assert_eq(len(array), 10);
    setitem(array, 5, 12);
    setitem(array, 6, 13);
    delete (it);
    delete (it_end);
    delete (array);
}

Test(new, test_newint)
{
    Object *integer = new (Int, 12);

    cr_assert_not_null(integer);
    cr_assert_str_eq(str(integer), "<Int (12)>");
    delete (integer);
}

Test(new, test_newchar)
{
    Object *character = new (Char, 'c');

    cr_assert_not_null(character);
    cr_assert_str_eq(str(character), "<Char (c)>");
    delete (character);
}

Test(new, test_newfloat)
{
    Object *floating = new (Float, 12.34);

    cr_assert_not_null(floating);
    cr_assert_str_eq(str(floating), "<Float (12.340000)>");
    delete (floating);
}

Test(new, test_newpoint)
{
    Object *point = new (Point, 12, 34);

    cr_assert_not_null(point);
    cr_assert_str_eq(str(point), "<Point (12, 34)>");
    delete (point);
}

Test(new, test_newvertex)
{
    Object *vertex = new (Vertex, 12, 34, 56);

    cr_assert_not_null(vertex);
    cr_assert_str_eq(str(vertex), "<Vertex (12, 34, 56)>");
    delete (vertex);
}

Test(new, test_ArrayIterator_eq)
{
    Object *array = new (Array, 10, Int, 0);

    Object *it = begin(array);
    Object *it_end = end(array);

    Object *it2 = begin(array);
    Object *it3 = end(array);
    // Test equality
    cr_assert_eq(eq(it, it2), 1);
    cr_assert_eq(eq(it, it3), 0);
    cr_assert_eq(eq(it_end, it3), 1);

    delete (it);
}

Test(new, test_ArrayIterator_gt)
{
    Object *array = new (Array, 10, Int, 0);

    Object *it = begin(array);
    Object *it_end = end(array);

    Object *it2 = begin(array);
    Object *it3 = end(array);
    // Test greater than
    cr_assert_eq(gt(it, it2), 0);
    cr_assert_eq(gt(it, it3), 0);
    cr_assert_eq(gt(it_end, it3), 0);

    delete (it);
}

Test(new, test_ArrayIterator_lt)
{
    Object *array = new (Array, 10, Int, 0);

    Object *it = begin(array);
    Object *it_end = end(array);

    Object *it2 = begin(array);
    Object *it3 = end(array);
    // Test less than
    cr_assert_eq(lt(it, it2), 0);
    cr_assert_eq(lt(it, it3), 1);
    cr_assert_eq(lt(it_end, it3), 0);

    delete (it);
}

Test(new, test_ArrayIterator_incr)
{
    Object *array = new (Array, 2, Int, 0);
    Object *it = begin(array);
    Object *it_end = end(array);

    incr(it);
    incr(it_end);
    cr_assert_eq(eq(it, it_end), 0);
}

Test(new, test_ArrayIterator_getval)
{
    Object *array = new (Array, 2, Int, 0);
    Object *it = begin(array);
    Object *it_prev = begin(array);

    incr(it);
    cr_assert_neq(getval(it), getval(it_prev));
}

Test(new, test_ArrayIterator_setval)
{
    Object *array = new (Array, 2, Int, 0);
    Object *it = begin(array);

    setval(it, 12);
    cr_assert_neq(begin(array), it);
}

Test(new, test_Array_getval_outofbond)
{
    Object *array = new (Array, 2, Int, 0);
    Object *it_end = end(array);

    int pipefd[2];
    pipe(pipefd);
    int pid = fork();

    if (pid == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDERR_FILENO);
        close(pipefd[1]);
        incr(it_end);
        getval(it_end);
        exit(0);
    } else {
        close(pipefd[1]);
        char buffer[256] = {0};
        read(pipefd[0], buffer, sizeof(buffer) - 1);
        close(pipefd[0]);
        waitpid(pid, NULL, 0);
        cr_assert_str_eq(buffer, "array.c: 55: Out of range\n",
            "Le message attendu dans stderr est incorrect !");
    }
    delete (array);
}

Test(new, test_Array_setval_outofbond)
{
    Object *array = new (Array, 2, Int, 0);
    Object *it_end = end(array);

    int pipefd[2];
    pipe(pipefd);
    int pid = fork();

    if (pid == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDERR_FILENO);
        close(pipefd[1]);
        setval(it_end, 15);
        exit(0);
    } else {
        close(pipefd[1]);
        char buffer[256] = {0};
        read(pipefd[0], buffer, sizeof(buffer) - 1);
        close(pipefd[0]);
        waitpid(pid, NULL, 0);
        cr_assert_str_eq(buffer, "array.c: 69: Index out of bounds\n",
            "Le message attendu dans stderr est incorrect !");
    }
    delete (array);
}

Test(new, test_charEmpty)
{
    Object *character = new (Char, '0');

    cr_assert_not_null(character);
    cr_assert_str_eq(str(character), "<Char (0)>");
    delete (character);
    character = new (Char);
    cr_assert_not_null(character);
}

Test(new, test_floatEmpty)
{
    Object *floating = new (Float, 0.0);

    cr_assert_not_null(floating);
    cr_assert_str_eq(str(floating), "<Float (0.000000)>");
    delete (floating);
    floating = new (Float);
    cr_assert_not_null(floating);
}

Test(new, test_intEmpty)
{
    Object *integer = new (Int, 0);

    cr_assert_not_null(integer);
    cr_assert_str_eq(str(integer), "<Int (0)>");
    delete (integer);
    integer = new (Int);
    cr_assert_not_null(integer);
}

Test(new, test_charFull)
{
    Object *character = new (Char, '0', 1);

    cr_assert_not_null(character);
    cr_assert_str_eq(str(character), "<Char (0)>");
    delete (character);
    character = new (Char, '1');
    cr_assert_not_null(character);
}

Test(new, test_floatFull)
{
    Object *floating = new (Float, 0.0, 1);

    cr_assert_not_null(floating);
    cr_assert_str_eq(str(floating), "<Float (0.000000)>");
    delete (floating);
    floating = new (Float, 1.0);
    cr_assert_not_null(floating);
}

Test(new, test_intFull)
{
    Object *integer = new (Int, 0, 1);

    cr_assert_not_null(integer);
    cr_assert_str_eq(str(integer), "<Int (0)>");
    delete (integer);
    integer = new (Int, 1);
    cr_assert_not_null(integer);
}

Test(new, test_pointEmpty)
{
    Object *point = new (Point);

    cr_assert_not_null(point);
    delete (point);
}

Test(new, test_vertexEmpty)
{
    Object *vertex = new (Vertex);

    cr_assert_not_null(vertex);
    delete (vertex);
}

Test(new, test_pointFull)
{
    Object *point = new (Point, 1, 2);

    cr_assert_not_null(point);
    cr_assert_str_eq(str(point), "<Point (1, 2)>");
    delete (point);
}

Test(new, test_vertexFull)
{
    Object *vertex = new (Vertex, 1, 2, 3);

    cr_assert_not_null(vertex);
    cr_assert_str_eq(str(vertex), "<Vertex (1, 2, 3)>");
    delete (vertex);
}
