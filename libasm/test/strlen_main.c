#include <stdio.h>

size_t ft_strlen(const char* s);

int main(void) {

	char *s1 = "salut\n";
	char *s2 = "";
	char *s3 = "hehehehehehehehe hop";

	printf("[%s]\n", s1);
	printf("[%ld]\n", ft_strlen(s1));
	printf("[%s]\n", s2);
	printf("[%ld]\n", ft_strlen(s2));
	printf("[%s]\n", s3);
	printf("[%ld]\n", ft_strlen(s3));

	return (0);
}
