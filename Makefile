NAME = output

BUFFER_SIZE = 33

SRCS_PATH = ./

OBJS_PATH = ./

SRCS_NAME = get_next_line.c \
	get_next_line_utils.c

SRCS = $(addprefix $(SRCS_PATH)/,$(SRCS_NAME))


OBJS = ${SRCS:.c=.o}


HEADER_DIR = ./

FLAG = -Wall -Wextra -Werror -I$(HEADER_DIR) -D BUFFER_SIZE=${BUFFER_SIZE}

CC = GCC $(FLAG) 

%.o:%.c
	$(CC) -o $@ -c -g $<

${NAME} : ${OBJS}
	# ar rcs $(NAME) $(OBJS)
	$(CC) -o $(NAME)  $(OBJS)


all : ${NAME}

clean :
	rm -f ${OBJS} $(OBJS_BONUS)
fclean : clean
	rm -f ${NAME}
re : fclean all

.PHONY : all clean fclean re