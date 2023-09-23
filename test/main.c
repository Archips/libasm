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

static int result;

void test_strlen(const char *s) {

    size_t ret1 = ft_strlen(s);
    int err1 = errno;

    size_t ret2 = strlen(s);
    int err2 = errno;

    if (ret1 == ret2 && err1 == err2)
       	result ++;
}

void test_strcmp(const char *s1, const char *s2) {

    int ret1 = ft_strcmp(s1, s2);
	int err1 = errno;

    int ret2 = strcmp(s1, s2);
    int err2 = errno;

	if (((!ret1 && !ret2) || (ret1 < 0 && ret2 < 0) || (ret1 > 0 && ret2 > 0)) && err1 == err2)
		result ++;
}

void test_write(int fd, const char *s, size_t size) {

    errno = 0;
	size_t ret1 = ft_write(fd, s, size);
    int err1 = errno;
    size_t ret2 = write(fd, s, size);
    int err2 = errno;
	if (ret1 == ret2 && err1 == err2) 
		result ++;
}

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
	printf("ft_strlen:\n\n");
	
	result = 0;
    
	test_strlen("");
    test_strlen("heyho");
    test_strlen("heyyyyy!");
    test_strlen("Hello this should work");
	
	printf("result : %d/4\n", result);
    printf("\n====================================\n");
    
	printf("\nft_strcmp:\n\n");

	result = 0;
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

	printf("result : %d/14\n", result);
    printf("\n====================================\n");
    
	printf("\nft_write:\n\n");

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
    
	printf("\nft_strcpy:\n\n");

	result = 0;

    test_strcpy("", "");
    test_strcpy("ah", "");
    test_strcpy("hey", "ho");
    test_strcpy("Ok this is more normal", "Yeayah");
    test_strcpy("Ok this is more normal", "as it is written, normal.");

	printf("result : %d/5\n", result);
    printf("\n====================================\n");
    
	printf("\nft_strdup:\n\n");

	result = 0;

    test_strdup("");
    test_strdup("heyho");
    test_strdup("heyyyyy!");
    test_strdup("Hello this should work");

	printf("result : %d/4\n", result);
    printf("\n====================================\n");

}
