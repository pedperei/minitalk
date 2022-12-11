NAME=libftprintf.a

C_FILES= ft_aux.c\
		 ft_hex.c\
		 ft_itoa_u.c\
		 ft_printf.c\
		 ft_ptr.c\
		 ft_select.c\
		 ft_putchar_fd.c\
		 ft_itoa.c\
		 ft_atoi.c


O_FILES= $(C_FILES:.c=.o) 

CC=cc
CFLAGS=-Wall -Wextra -Werror -I. -c -fPIE -o
ARRC = ar -crs
REMOVE = rm -rf

all: $(NAME)

$(NAME): $(O_FILES)
	$(ARRC) $(NAME) $? $(SUB_DIR)$(O_FILES)

%.o: %.c
	$(CC) $(CFLAGS) $@ $^ 

clean:
	rm -f $(O_FILES)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
