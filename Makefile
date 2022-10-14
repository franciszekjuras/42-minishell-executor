NAME = libexecutor.a

FILES = \
	executor

HEADERS = \
	executor

HFILES = $(HEADERS:%=%.h)
OFILES = $(FILES:%=%.o)

CFLAGS = -Wall -Wextra -Werror

INC = -I..

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $@ $?

$(OFILES): %.o: %.c $(HFILES)
	gcc $(CFLAGS) $(OPTIM) $(INC) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
