NAME = libftprintf.a

SRCS = $(wildcard ft_*.c)

SRCS_BONUS = $(wildcard ft_*bonus.c)


OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(SRCS_BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = libft.h 

AR = ar rcs

RM = rm -f 

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)


re: fclean all