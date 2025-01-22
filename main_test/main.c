/*
** EPITECH PROJECT, 2025
** Rush2
** File description:
** main
*/

#include "../include/my.h"

int main(void)
{
    Object  *point = new(Point, 42, -42);
    Object  *vertex = new(Vertex, 0, 1, 2);

    printf("point = %s\\n", str(point));
    printf("vertex = %s\\n", str(vertex));

    delete(point);
    delete(vertex);
    return (0);
}