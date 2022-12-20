NAME	=	
CLIENT	=	client
SERVER	=	server

C_FILES_SERVER= ft_putnbr_fd.c\
		 		ft_putstr_fd.c\
		 		server.c\

C_FILES_CLIENT= ft_atoi.c\
		 		client.c\
		 
CC=cc
CFLAGS=-Wall -Wextra -Werror
REMOVE = rm -rf


GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER):
	@ $(CC) $(CFLAGS) $(C_FILES_SERVER) -o $(SERVER)
	@printf "$(_SUCCESS) server ready.\n"

$(CLIENT):
	@ $(CC) $(CFLAG) $(C_FILES_CLIENT) -o $(CLIENT)
	@printf "$(_SUCCESS) client ready.\n"

clean:
	rm -f $(CLIENT) $(SERVER)

fclean: clean

re: fclean all	

bonus: $(BONUS_O_FILES)
	$(ARRC) $(NAME) $(BONUS_O_FILES)

.PHONY: all clean fclean re bonus
