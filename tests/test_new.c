#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>
#include <stdio.h>
#include "my.h"
#include "new.h"

Test(new, valid_class)
{
    Class class = {
        .__size__ = sizeof(Class),
        .__ctor__ = NULL,
        .__dtor__ = NULL
    };
    Object *obj = new(&class);

    cr_assert_not_null(obj, "Object creation failed");
    cr_assert_eq(((Class *)obj)->__size__, sizeof(Class), "Object size mismatch");
    free(obj);
}

// Test(new, null_class_size)
// {
//     Class class = {
//         .__size__ = 0,
//         .__ctor__ = NULL,
//         .__dtor__ = NULL
//     };

//     cr_assert_raise(new(&class), "Error: size is NULL");
// }

// Test(new, malloc_failure)
// {
//     Class class = {
//         .__size__ = sizeof(Class),
//         .__ctor__ = NULL,
//         .__dtor__ = NULL
//     };

//     // Simulate malloc failure
//     cr_redirect_stderr();
//     cr_assert_raise(new(&class), "Error: malloc failed");
// }

Test(new, valid_ctor)
{
    Class class = {
        .__size__ = sizeof(Class),
        .__ctor__ = NULL,
        .__dtor__ = NULL
    };
    Object *obj = new(&class);

    cr_assert_not_null(obj, "Object creation failed");
    cr_assert_eq(((Class *)obj)->__size__, sizeof(Class), "Object size mismatch");
    free(obj);
}

// Test(new, null_ctor)
// {
//     Class class = {
//         .__size__ = sizeof(Class),
//         .__ctor__ = NULL,
//         .__dtor__ = NULL
//     };

//     cr_assert_raise(new(&class), "Error: ctor is NULL");
// }

Test(new, valid_dtor)
{
    Class class = {
        .__size__ = sizeof(Class),
        .__ctor__ = NULL,
        .__dtor__ = NULL
    };
    Object *obj = new(&class);

    cr_assert_not_null(obj, "Object creation failed");
    cr_assert_eq(((Class *)obj)->__size__, sizeof(Class), "Object size mismatch");
    delete(obj);
}
