NAME		=	Animals

CXX			=	c++

SRCS		=	Animal.cpp 	    \
				Dog.cpp	 		\
				Cat.cpp	 		\
				Brain.cpp		\
				main.cpp

CXXFLAGS	=	-Wall -Wextra -Werror -g -Wshadow -std=c++98 #-fsanitize=address

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