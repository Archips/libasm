#include "libasm.h"

static int result;

void test_strcpy(char * dst, const char * src) {

    char *dst1 = malloc(sizeof(char) * 100);
    char *dst2 = malloc(sizeof(char) * 100);

    if (!dst1 || !dst2) {
        ft_write(1, "error\n", 6);
        return;
    }

    strcpy(dst1, dst);
    strcpy(dst2, dst);

    char *ret1 = ft_strcpy(dst1, src);
    int err1 = errno;

    char *ret2 = strcpy(dst2, src);
    int err2 = errno;

    if (!strcmp(ret1, dst1) && !strcmp(ret2, dst2) && err1 == err2) {
        result ++;
    }

    if (dst1)
        free(dst1);
    if (dst2)
        free(dst2);
}

int		main(void)
{

    printf("ft_strcpy:\n\n");

    result = 0;

    test_strcpy("", "");
    test_strcpy("ah", "");
    test_strcpy("hey", "ho");
    test_strcpy("Ok this is more normal", "Yeayah");
    test_strcpy("Ok this is more normal", "as it is written, normal.");

    printf("result : %d/5\n", result);
    printf("\n====================================\n");

}
