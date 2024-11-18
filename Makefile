OBJS = ft_printf.o ft_putchar_count.o ft_putstr_count.o ft_putnbr_count.o
FLAGS = -Wall -Wextra -Werror -c
COMPILE = cc $(FLAGS)
NAME = libftprintf.a
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	cp libft/libft.a $@
	ar rs $(NAME) $(OBJS)

$(LIBFT):
	make -C libft

%.o: %.c $(LIBFT_H) printf.h
	$(COMPILE) $< -o $@

clean: 
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: clean link