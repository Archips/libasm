#include "libasm.h"

static int result;

void test_strcmp(const char *s1, const char *s2) {

    int ret1 = ft_strcmp(s1, s2);
    int err1 = errno;

    int ret2 = strcmp(s1, s2);
    int err2 = errno;

    if (((!ret1 && !ret2) || (ret1 < 0 && ret2 < 0) || (ret1 > 0 && ret2 > 0)) && err1 == err2)
        result ++;
}

int		main(void)
{

    printf("ft_strcmp:\n\n");

    result = 0;
    test_strcmp("Hello", "Hello");
    test_strcmp("Hello!", "Hello");
    test_strcmp("Hello", "Hello!");
    test_strcmp("He!!o", "Hello");
    test_strcmp("Hello", "He!!o");

    test_strcmp("Hello\tHi", "Hello\tHi");
    test_strcmp("Hello\200Hi", "Hello\0Hi");
    test_strcmp("Hello\0Hi", "Hello\200Hi");
    test_strcmp("Hello\200Hi", "Hello\200Hi");
    test_strcmp("Hello\0Hi", "Hello\0Hi");

    test_strcmp("This string is longer", "This string is longer");
    test_strcmp("You might pass all these tests", "Or not");
    test_strcmp("or not", "Or not");
    test_strcmp("or noT", "or not");

    printf("result : %d/14\n", result);
    printf("\n====================================\n");

}
