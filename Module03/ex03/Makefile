NAME		=	DiamondTrap

CXX			=	c++

SRCS		=	ClapTrap.cpp \
				FragTrap.cpp \
				ScavTrap.cpp \
				DiamondTrap.cpp \
				main.cpp

CXXFLAGS	=	-Wall -Wextra -Werror -g -std=c++98 -Wno-shadow #-fsanitize=address

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