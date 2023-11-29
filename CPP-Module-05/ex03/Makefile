CC = c++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98

RM = rm -f

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = ex03

%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJS) *_shrubbery

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re