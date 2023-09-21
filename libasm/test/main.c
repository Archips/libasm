#include <string.h>
#include <errno.h>
#include <stdio.h>

size_t ft_strlen(const char *s);


void test_strlen(const char *s) {

    size_t ret1 = ft_strlen(s);
    int err1 = errno;

    size_t ret2 = strlen(s);
    int err2 = errno;

    if (ret1 == ret2 && err1 == err2) {
        printf("OK\n");
    } else {
        printf("KO\n");
    }
}

int		main(void)
{
    test_strlen("");
    test_strlen("heyho");
    test_strlen("heyyyyy!");
    test_strlen("Hello this should work");
}
