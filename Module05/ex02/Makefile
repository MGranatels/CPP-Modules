NAME		=	Converter

CXX			=	c++

SRCS		=	main.cpp \
				Bureaucrat.cpp \
				Aform.cpp \
				PresidentialPardonForm.cpp \

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

re:			fclean all

.PHONY:		all clean fclean re