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

test:
	gcc -Wall -Wextra -Werror test/main.c -o tester -L. -lasm 

clean: 
	${RM} -r obj

fclean: clean
	${RM} ${NAME} tester

re: fclean all
