#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

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
        if (ret1)
			free(ret1);
        if (ret2)
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

	printf("fd not open\n");
    test_write(9, "Hello\n", 6);
	printf("-----------\n");
    
	printf("all good\n");
	test_write(0, "Hello!\n", 7);
	printf("-----------\n");
    
	printf("char * is NULL\n");
	test_write(0, NULL, 5);
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

    printf("\n====================================\n");
    printf("\nft_read:\n\n");

	char buf[1024];
	char c;
	printf("Standard Input\n");
	test_read(0, buf, 6);
	printf("buf [%s]\n", buf);
	printf("-----------\n");

	printf("Readable\n");
	/* bzero(buf, 1024); */
	fd = open("./files/readable", O_RDONLY);
	while (ft_read(fd, &c, 1))
		ft_write(1, &c, 1);
	close(fd);
	/* printf("buf [%s]\n", buf); */
	printf("-----------\n");
    /* test_read(9, 9, 5); */
    /* test_read(9, 9, 9); */

    /* test_read(1, 1, 5); */
    /* test_read(1, 1, 1); */
    /* test_read(1, 1, 9); */
    /* test_read(1, 1, 7); */
    /* test_read(1, 1, 18); */
    /* test_read(1, 1, 30); */

    /* test_read(-1, 4, 5); */
    /* test_read(-1, 4, 1); */
    /* test_read(-1, 4, 9); */
    /* test_read(-1, 4, 7); */
    /* test_read(-1, 4, 18); */
    /* test_read(-1, 4, 30); */

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
