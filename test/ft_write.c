#include "libasm.h"

static int result;

void test_write(int fd, const char *s, size_t size) {

    errno = 0;
    size_t ret1 = ft_write(fd, s, size);
    int err1 = errno;
    size_t ret2 = write(fd, s, size);
    int err2 = errno;
    if (ret1 == ret2 && err1 == err2)
        result ++;
}

int		main(void)
{
    printf("ft_write:\n\n");

    result = 0;

    printf("fd not open\n");
    test_write(9, "Hello\n", 6);
    printf("-----------\n");

    printf("all good\n");
    test_write(1, "Hello!\n", 7);
    printf("-----------\n");

    printf("char * is NULL\n");
    test_write(1, NULL, 5);
    printf("-----------\n");

    printf("Not writtable\n");
    int fd = open("./files/no_writting_right", O_RDWR);
    test_write(fd, "hello\n", 6);
    close(fd);
    printf("-----------\n");

    printf("No rights\n");
    fd = open("./files/no_rights", O_RDWR);
    test_write(fd, "hello\n", 6);
    close(fd);
    printf("-----------\n");

    printf("Writtable\n");
    fd = open("./files/write", O_RDWR);
    test_write(fd, "hello\n", 6);
    close(fd);
    printf("-----------\n");

    printf("Size < 0\n");
    test_write(1, "hello\n", -4);
    printf("-----------\n");

    printf("result : %d/7\n", result);
    printf("\n====================================\n");

}

