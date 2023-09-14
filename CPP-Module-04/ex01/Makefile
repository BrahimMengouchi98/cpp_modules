CC = c++

CPPFLAGS = -Wall -Werror -Wextra -g -std=c++98

RM = rm -f

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = ex01

all: $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re