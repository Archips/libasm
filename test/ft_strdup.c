#include "libasm.h"

static int result;

void test_strdup(const char *s1) {

    char *ret1 = ft_strdup(s1);
    int err1 = errno;

    char *ret2 = strdup(s1);
    int err2 = errno;

    if (ret1 && ret2 && !strcmp(ret1, ret2) && err1 == err2)
        result ++;

    if (ret1)
        free(ret1);
    if (ret2)
        free(ret2);
}

int		main(void)
{
    printf("\nft_strdup:\n\n");

    result = 0;

    test_strdup("");
    test_strdup("heyho");
    test_strdup("heyyyyy!");
    test_strdup("Hello this should work");

    printf("result : %d/4\n", result);
    printf("\n====================================\n");

}

