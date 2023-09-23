#include "libasm.h"

static int result;

void test_read(int fd, size_t nbyte, char *filename) {

    char *buf1;
    char *buf2;
    int err1 = 0;
    int err2 = 0;
    errno = 0;

    buf1 = malloc(1024);
    buf2 = malloc(1024);
    if (!buf1 || !buf2) {
        printf("error\n");
        return;
    }
    bzero(buf1, 1024);
    bzero(buf2, 1024);

    if (fd == 0 && !filename) {
        ft_read(0, buf1, nbyte);
        printf("> %s", buf1);
        err2 = errno;
        read(0, buf2, nbyte);
        printf("> %s", buf2);
        err2 = errno;
    }
    else
    {
        fd = open(filename, O_RDONLY);
        while (ft_read(fd, buf1, nbyte) > 0)
            ;
        err1 = errno;
        printf("> %s", buf1);
        close(fd);
        fd = open(filename, O_RDONLY | O_NONBLOCK);
        while (read(fd, buf2, nbyte) > 0)
            ;
        err2 = errno;
        printf("> %s", buf2);
        close(fd);
    }

    if (!strcmp(buf1, buf2) && err1 == err2)
        result ++;

    if (buf1)
        free(buf1);
    if (buf2)
        free(buf2);
}

int		main(void)
{
    printf("\nft_read:\n\n");

    result = 0;

    printf("Standard Input\n");
    test_read(0, 6, NULL);
    printf("-----------\n");

    printf("Readable\n");
    test_read(-1, 1024, "./files/readable");
    printf("-----------\n");

    printf("Readable but empty\n");
    test_read(-1, 1024, "./files/readable_but_empty");
    printf("-----------\n");

    printf("Readable | size = 0\n");
    test_read(-1, 0, "./files/readable");
    printf("-----------\n");

    printf("Readable | size less than the whole file\n");
    test_read(-1, 3, "./files/readable");
    printf("-----------\n");

    printf("Readable | size bigger than the whole file\n");
    test_read(-1, 10, "./files/small_readable");
    printf("-----------\n");

    /* printf("Readable | size bigger than buffer size"); */
    /* test_read(-1, 2000, "./files/readable"); */
    /* printf("-----------\n"); */

    /* printf("File doesn't exist"); */
    /* test_read(-1, 1024, "./files/file_does_not_exist"); */
    /* printf("-----------\n"); */

    /* printf("No rights\n"); */
    /* test_read(-1, 1024, "./files/no_rights"); */
    /* printf("-----------\n"); */

    /* printf("Fd is a directory\n"); */
    /* test_read(-1, 1024, "./files/"); */
    /* printf("-----------\n"); */

    printf("result : %d/6\n", result);
    printf("\n====================================\n");

}
