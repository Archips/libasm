#include <stdio.h>
#include <string.h>

int ft_strcmp(const char *s1, const char *s2);

int main(void) {

	printf("1:  %d\n", ft_strcmp("hello", "hello"));
	printf("2:  %d\n", ft_strcmp("hello", "helloooo"));
	printf("3:  %d\n", ft_strcmp("hello", "hella"));

	printf("4:  %d\n", ft_strcmp("Hello", "Hello"));
	printf("5:  %d\n", ft_strcmp("Hello!", "Hello"));
	printf("6:  %d\n", ft_strcmp("Hello", "Hello!"));
	printf("7:  %d\n", ft_strcmp("He!!o", "Hello"));
	printf("8:  %d\n", ft_strcmp("Hello", "He!!o"));
	printf("9:  %d\n", ft_strcmp("Hello\tHi", "Hello\tHi"));
	printf("10: %d\n", ft_strcmp("Hello\200Hi", "Hello\0Hi"));
	printf("11: %d\n", ft_strcmp("Hello\0Hi", "Hello\200Hi"));
	printf("12: %d\n", ft_strcmp("Hello\200Hi", "Hello\200Hi"));
	printf("13: %d\n", ft_strcmp("Hello\0Hi", "Hello\0Hi"));
	printf("14: %d\n", ft_strcmp("", ""));
	printf("15: %d\n", ft_strcmp("This string is longer", "This string is longer"));
	printf("16: %d\n", ft_strcmp("You might pass all these tests", "Or not"));
	printf("17: %d\n", ft_strcmp("or not", "Or not"));
	printf("18: %d\n", ft_strcmp("or noT", "or not"));
	printf("----------------------------------\n");
	printf("1:  %d\n", strcmp("hello", "hello"));
	printf("2:  %d\n", strcmp("hello", "helloooo"));
	printf("3:  %d\n", strcmp("hello", "hella"));

	printf("4:  %d\n", strcmp("Hello", "Hello"));
	printf("5:  %d\n", strcmp("Hello!", "Hello"));
	printf("6:  %d\n", strcmp("Hello", "Hello!"));
	printf("7:  %d\n", strcmp("He!!o", "Hello"));
	printf("8:  %d\n", strcmp("Hello", "He!!o"));
	printf("9:  %d\n", strcmp("Hello\tHi", "Hello\tHi"));
	printf("10: %d\n", strcmp("Hello\200Hi", "Hello\0Hi"));
	printf("11: %d\n", strcmp("Hello\0Hi", "Hello\200Hi"));
	printf("12: %d\n", strcmp("Hello\200Hi", "Hello\200Hi"));
	printf("13: %d\n", strcmp("Hello\0Hi", "Hello\0Hi"));
	printf("14: %d\n", strcmp("", ""));
	printf("15: %d\n", strcmp("This string is longer", "This string is longer"));
	printf("16: %d\n", strcmp("You might pass all these tests", "Or not"));
	printf("17: %d\n", strcmp("or not", "Or not"));
	printf("18: %d\n", strcmp("or noT", "or not"));

	return (0);
}
