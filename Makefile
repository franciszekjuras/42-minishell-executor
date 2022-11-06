NAME = libexecutor.a

FILES = \
	executor exec_data childs app app_priv utils \
	builtins lineops envops var_valid\

HFILES := $(FILES:%=%.h)

HFILES += ../interface/line.h

FILES += \
	app_priv2 envops2 builtins2 builtins3

OFILES := $(FILES:%=%.o)

CFLAGS = -Wall -Wextra -Werror -fprofile-arcs -ftest-coverage

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
