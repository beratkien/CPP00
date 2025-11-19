NAME = phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Contact.cpp PhoneBook.cpp
RM = rm -f
all: $(NAME)
$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
fclean:
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re