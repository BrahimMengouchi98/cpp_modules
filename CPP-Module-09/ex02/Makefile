CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRCS = main.cpp PmergeMe.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = PmergeMe

%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re