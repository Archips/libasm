#include <stdio.h>
#include <unistd.h>

ssize_t ft_write(int fd, const void *buf, size_t count);

int main(void) {

	ssize_t x =	ft_write(1, "hello", 10);
	printf("\nSize is [%ld]\n", x);
	/* printf("\n[%ld]\n",ft_write(1, "hello", 10)); */
	/* printf("\n"); */
	/* printf("\n[%ld]\n", write(1, "hello", 10)); */
	return 0;
}
