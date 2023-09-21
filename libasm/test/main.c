#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t  ft_strlen(const char *s);
int     ft_strcmp(const char *s1, const char *s2);
size_t  ft_write(int fd, const char *s, size_t size);
size_t  ft_read(int fd, void *buf, size_t nbyte);
char *  ft_strcpy(char * dst, const char * src);
char *  ft_strdup(const char *s1);

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

void test_strcmp(const char *s1, const char *s2) {

    int ret1 = ft_strcmp(s1, s2);
	int err1 = errno;

    int ret2 = strcmp(s1, s2);
    int err2 = errno;

	if (((!ret1 && !ret2) || (ret1 < 0 && ret2 < 0) || (ret1 > 0 && ret2 > 0)) && err1 == err2) {
        printf("OK\n");
    } else {
        printf("KO\n");
    }
}

void test_write(int fd, const char *s, size_t size) {

    errno = 0;
	size_t ret1 = ft_write(fd, s, size);
    int err1 = errno;
    size_t ret2 = write(fd, s, size);
    int err2 = errno;
	if (fd < 0 || fd > 2)
		printf("wrong fd\n");
	if (!s)
		printf("s is NULL\n");
	if (size < 1)
		printf("wrong size\n");
	printf("err1 = %d && err2 = %d\n", err1, err2);
	if (ret1 == ret2 && err1 == err2) {
        printf("OK\n");
    } else {
        printf("KO\n");
    }
}

void test_read(int fd, void *buf, size_t nbyte) {

        errno = 0;
        size_t ret1 = ft_read(fd, buf, nbyte);
        int err1 = errno;
        size_t ret2 = read(fd, buf, nbyte);
        int err2 = errno;
        if (fd < 0 || fd > 2)
            printf("wrong fd\n");
        if (!buf)
            printf("buf is NULL\n");
        if (nbyte < 1)
            printf("wrong size\n");
        printf("err1 = %d && err2 = %d\n", err1, err2);
        if (ret1 == ret2 && err1 == err2) {
            printf("OK\n");
        } else {
            printf("KO\n");
        }
}

void test_strcpy(char * dst, const char * src) {

        char *dst1 = malloc(sizeof(char) * 100);
        char *dst2 = malloc(sizeof(char) * 100);

        strcpy(dst1, dst);
        strcpy(dst2, dst);

        char *ret1 = ft_strcpy(dst1, src);
        int err1 = errno;

        char *ret2 = strcpy(dst2, src);
        int err2 = errno;

        if (!strcmp(ret1, dst1) && !strcmp(ret2, dst2) && err1 == err2) {
            printf("OK\n");
        } else {
            printf("KO\n");
        }
        free(dst1);
        free(dst2);
}

void test_strdup(const char *s1) {

        char *ret1 = ft_strdup(s1);
        int err1 = errno;

        char *ret2 = strdup(s1);
        int err2 = errno;

        if (ret1 && ret2 && !strcmp(ret1, ret2) && err1 == err2) {
            printf("OK\n");
        } else {
            printf("KO\n");
        }
        free(ret1);
        free(ret2);
}

int		main(void)
{
    printf("ft_strlen:\n\n");

    test_strlen("");
    test_strlen("heyho");
    test_strlen("heyyyyy!");
    test_strlen("Hello this should work");

    printf("\n====================================\n");
    printf("\nft_strcmp:\n\n");

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

    printf("\n====================================\n");
    printf("\nft_write:\n\n");

    test_write(9, "Hello\n", 6);
    test_write(0, "Hello!\n", 7);
    test_write(0, NULL, 5);
    test_write(-1, NULL, 5);
    test_write(0, "ABCEDFGEF\nGH\n", 10);
    test_write(9, "ABCEDFGEF\nGH\n", 10);
    test_write(0, NULL, -1);
    test_write(0, "A longer sentence!\n", 19);

    test_write(1, "Hello!\n", 7);
    test_write(1, NULL, 5);
    test_write(1, NULL, -1);
    test_write(1, "A longer sentence!\n", 19);

//    printf("\n====================================\n");
//    printf("\nft_read:\n\n");
//
//    test_read(9, 9, 5);
//    test_read(9, 9, 9);
//
//    test_read(rdfd, rdfd_true, 5);
//    test_read(rdfd, rdfd_true, 1);
//    test_read(rdfd, rdfd_true, 9);
//    test_read(rdfd, rdfd_true, 7);
//    test_read(rdfd, rdfd_true, 18);
//    test_read(rdfd, rdfd_true, 30);
//
//    test_read(wrfd, wrfd, 5);
//    test_read(wrfd, wrfd, 1);
//    test_read(wrfd, wrfd, 9);
//    test_read(wrfd, wrfd, 7);
//    test_read(wrfd, wrfd, 18);
//    test_read(wrfd, wrfd, 30);

    printf("\n====================================\n");
    printf("\nft_strcpy:\n\n");

    test_strcpy("", "");
    test_strcpy("ah", "");
    test_strcpy("hey", "ho");
    test_strcpy("Ok this is more normal", "Yeayah");
    test_strcpy("Ok this is more normal", "as it is written, normal.");

    printf("\n====================================\n");
    printf("\nft_strdup:\n\n");

    test_strdup("");
    test_strdup("heyho");
    test_strdup("heyyyyy!");
    test_strdup("Hello this should work");

}
