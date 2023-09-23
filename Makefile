.PHONY: all clean fclean re test

src = src/ft_strlen.s \
	   src/ft_strcpy.s \
	   src/ft_strcmp.s \
	   src/ft_write.s \
	   src/ft_read.s \
	   src/ft_strdup.s

OBJS = ${patsubst src/%.s,obj/%.o,$(src)}
NAME = libasm.a
CC = nasm -f elf64
RM = rm -rf

all: obj ${NAME}

obj:
	mkdir -p obj

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

obj/%.o: src/%.s
	${CC} $< -o $@

strlen:
	clang -Wall -Wextra -Werror test/ft_strlen.c -o strlen -L. -lasm

strcmp:
	clang -Wall -Wextra -Werror test/ft_strcmp.c -o strcmp -L. -lasm

strcpy:
	clang -Wall -Wextra -Werror test/ft_strcpy.c -o strcpy -L. -lasm

strdup:
	clang -Wall -Wextra -Werror test/ft_strdup.c -o strdup -L. -lasm

write:
	clang -Wall -Wextra -Werror test/ft_write.c -o write -L. -lasm

read:
	clang -Wall -Wextra -Werror test/ft_read.c -o read -L. -lasm

test_all:
	clang -Wall -Wextra -Werror test/main.c -o tester -L. -lasm 

clean: 
	${RM} -r obj

fclean: clean
	${RM} ${NAME} tester

re: fclean all
