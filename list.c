// /*
// ** EPITECH PROJECT, 2025
// ** Paradigms Seminar
// ** File description:
// ** Exercice 06
// */

// #include "include/my.h"

// typedef struct ListClass {
//     My_Container base;
//     Object *data;
//     struct ListClass *next;
// } ListClass;

// static void List_ctor(ListClass *this, va_list *args)
// {
//     this->data = va_new(va_arg(*args, Class *), args);
//     this->next = NULL;
// }

// static void List_dtor(ListClass *this)
// {
//     delete(this->data);
//     if (this->next)
//         delete(this->next);
//     free(this->next);
// }

// static void List_str(ListClass *this)
// {
//     str(this->data);
//     if (this->next) {
//         printf(", ");
//         List_str(this->next);
//     }
// }

// static bool List_eq(ListClass *this, ListClass *other)
// {
//     if (eq(this->data, other->data) == 0)
//         return false;
//     if (this->next && other->next)
//         return eq(this->next, other->next);
//     if (!this->next && !other->next)
//         return true;
//     return false;
// }

// static const ListClass _description = {
//     {
//         {
//             /* Class struct */
//             .__size__ = sizeof(ListClass),
//             .__name__ = "List",
//             .__ctor__ = (ctor_t) &List_ctor,
//             .__dtor__ = (dtor_t) &List_dtor,
//             .__str__ = (to_string_t) &List_str,
//             .__add__ = NULL,
//             .__sub__ = NULL,
//             .__mul__ = NULL,
//             .__div__ = NULL,
//             .__eq__ = (binary_operator_t) &List_eq,
//             .__gt__ = NULL,
//             .__lt__ = NULL,
//         },
//         // .__len__ = (len_t) &List_len,
//         // .__begin__ = (iter_t) &List_begin,
//         // .__end__ = (iter_t) &List_end,
//         // .__getitem__ = (getitem_t) &List_getitem,
//         // .__setitem__ = (setitem_t) &List_setitem,
//     },
//     .data = NULL,
//     .next = NULL
// };

// const Class *List = (const Class *)&_description;
