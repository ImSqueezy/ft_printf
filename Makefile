OBJS = hello.o hello1.o str.o
FLAGS = -Wall -Wextra -Werror -c
COMPILE = cc $(FLAGS)

all: libftprintf.a printf.h

libftprintf.a: $(OBJS)
%.o: %.c
	$(COMPILE) $< -o $@
	ar r libftprintf.a $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f libftprintf.a

re: fclean all

.PHONY: clean re