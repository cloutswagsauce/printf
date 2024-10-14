NAME = libftprintf.a

SRCS = ft_printf.c helper_funcs/print_di.c helper_funcs/print_p.c helper_funcs/print_s.c helper_funcs/print_u.c helper_funcs/print_xX.c

OBJS = $(SRCS:.c=.o)


CC = cc

CFLAGS = -Wall -Wextra -Werror -I./includes/

HEADER = ft_printf.h 

AR = ar rcs

RM = rm -f 

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft_notmine
	cp libft_notmine/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re