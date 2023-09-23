#include "libasm.h"

static int result;

void test_strlen(const char *s) {

    size_t ret1 = ft_strlen(s);
    int err1 = errno;

    size_t ret2 = strlen(s);
    int err2 = errno;

    if (ret1 == ret2 && err1 == err2)
        result ++;
}

int		main(void)
{
    printf("ft_strlen:\n\n");

    result = 0;

    test_strlen("");
    test_strlen("heyho");
    test_strlen("heyyyyy!");
    test_strlen("Hello this should work");

    printf("result : %d/4\n", result);
    printf("\n====================================\n");

}
