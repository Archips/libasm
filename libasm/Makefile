.PHONY: all clean fclean re

SRCS = srcs/ft_strlen.s \
	   srcs/ft_strcpy.s \
	   srcs/ft_strcmp.s \
	   srcs/ft_write.s \
	   srcs/ft_read.s \
	   srcs/ft_strdup.s

OBJ_DIR = objs
OBJS = ${SRCS:%.s=$(OBJ_DIR)/%.o}
NAME = libasm.a
CC = nasm -f elf64
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

${OBJ_DIR}/%.o: %.s
	mkdir -p ${OBJ_DIR}
	${CC} -o $@

clean: 
	${RM} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all
