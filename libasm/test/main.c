#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

size_t  ft_strlen(const char *s);
int     ft_strcmp(const char *s1, const char *s2);
size_t ft_write(int fd, const char *s, size_t size);

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
}
