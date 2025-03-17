OBJS = ft_printf.o putchar_count.o puthex_count.o putnbr_count.o \
	putstr_count.o putu_count.o putptr_count.o
FLAGS = -Wall -Wextra -Werror
COMPILE = cc $(FLAGS)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) 
	ar rs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(COMPILE) -c $<

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
