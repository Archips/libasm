int	ft_strcmp(char *s1, char *s2) {

	while (*s1 && *s2 && *s1 == *s2)
	{
		s1 ++;
		s2 ++;
	}
	return (*s1 - *s2);
}

/* int main(void) { */

/* 	printf("%d", ft_strcmp("hello", "hello")); */
/* 	printf("%d", ft_strcmp("hello", "helloooo")); */
/* 	return (0); */
/* } */
