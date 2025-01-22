/*
** EPITECH PROJECT, 2025
** Rush2
** File description:
** ex06
*/

#include "../include/my.h"

int main(void)
{
    Object *int1 = new(Char, 'a');
    Object *list = new(List, int1, NULL);
    Object *it = begin(list);
    Object *it_end = end(list);

    l_pushfront(list, new(Char, 'b'));
    l_pushfront(list, new(Char, 'c'));
    l_pushback(list, new(Char, 'd'));
    l_pushback(list, new(Int, 3));
    printf("list size: %zu\n", len(list));
    for(int i = 0; i < l_len(list); i++)
        printf("%s\n", str(l_getitem(list, i)));
    str(list);
    return 0;
}
