CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
PROG = mini_shell
LIBFT = Libft/libft.a
SOURCES = mini_shell.c ft_split.c utils.c unset_builtin.c ft_execute.c parse_redirect.c  ft_error.c handle_couts.c $(LIBFT)

OBJECTS = $(SOURCES:.c=.o)

all : $(PROG)
$(LIBFT) :
	make -C libft
$(PROG) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -lreadline -o $(PROG)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) $(PROG) $(LIBFT)

bonus: all
	ar rc $(NAME)

re: fclean all
