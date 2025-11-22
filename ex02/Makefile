NAME = account
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Account.cpp tests.cpp 
RM = rm -f
all: $(NAME)
$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
clean:
	$(RM) $(NAME)
fclean: clean

re: fclean all
.PHONY: all clean fclean re