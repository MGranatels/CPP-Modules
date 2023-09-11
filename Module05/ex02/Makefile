NAME		=	Converter

CXX			=	c++

SRCS		=	main.cpp \
				Bureaucrat.cpp \
				AForm.cpp \
				PresidentialPardonForm.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp

CXXFLAGS	=	-Wall -Wextra -Werror -g -std=c++98 #-fsanitize=address

RM			=	rm -f

OBJS		=	$(SRCS:%.cpp=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(SRCS) $(CXXFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) trees.txt

re:			fclean all

.PHONY:		all clean fclean re