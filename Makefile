OBJS = hello.o ft_putchar.o
FLAGS = -Wall -Wextra -Werror -c
COMPILE = cc $(FLAGS)
NAME = printf.a

all: $(NAME) printf.h

$(NAME): $(OBJS)

%.o: %.c
	$(COMPILE) $< -o $@
	ar r libftprintf.a $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean