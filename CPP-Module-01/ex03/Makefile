CC = c++

CPPFLAGS = -Wall -Werror -Wextra -g -std=c++98

RM = rm -f

SRCS = main.cpp HumanA.cpp Weapon.cpp HumanB.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = weapon

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re