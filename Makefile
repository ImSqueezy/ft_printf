OBJS = ft_printf.o ft_putchar_count.o ft_putstr_count.o ft_putnbr_count.o \
	ft_putu_count.o ft_puthex_count.o
FLAGS = -Wall -Wextra -Werror -c
COMPILE = cc $(FLAGS)
NAME = libftprintf.a
LIBFT = Libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	cp Libft/libft.a $@
	ar rs $(NAME) $(OBJS)

$(LIBFT):
	make -C Libft

%.o: %.c $(LIBFT_H) printf.h
	$(COMPILE) $< -o $@

clean: 
	rm -f $(OBJS)
	make clean -C Libft

fclean: clean
	rm -f $(NAME)
	make fclean -C Libft

re: fclean all

.PHONY: clean