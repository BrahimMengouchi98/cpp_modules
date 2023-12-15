CC = c++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98

RM = rm -f

SRCS = main.cpp Span.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = ex01

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