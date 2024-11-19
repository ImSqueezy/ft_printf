SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -c
COMPILE = cc $(FLAGS)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) 
	ar rs $(NAME) $(OBJS)

%.o: %.c printf.h
	$(COMPILE) $<

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean