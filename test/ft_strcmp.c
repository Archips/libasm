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
    test_strcmp("Salut", "Salut");
    test_strcmp("Salut!", "Salut");
    test_strcmp("Salut", "Salut!");
    test_strcmp("He!!o", "Salut");
    test_strcmp("Salut", "Sa!ut");

    test_strcmp("salut\tHola", "salut\tHola");
    test_strcmp("salut\200Hola", "salut\0Hola");
    test_strcmp("salut\0Hola", "salut\200Hola");
    test_strcmp("salut\200Hola", "salut\200Hola");
    test_strcmp("salut\0Hola", "salut\0Hola");

    test_strcmp("Hellooooooooooooooo", "Hellooooooooooooooo");
    test_strcmp("That's a lot of tests", "That's life");
    test_strcmp("or not", "Or not");
    test_strcmp("it is", "it iS");

    printf("result : %d/14\n", result);
    printf("\n====================================\n");

}
