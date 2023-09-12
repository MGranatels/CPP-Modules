CXX			= 	g++ -std=c++98
CXXFLAGS		= 	-Wall -Wextra -Werror -Wshadow  -g\
				# -fsanitize=address
NAME		= 	bureau
SRCS		=	$(wildcard *.cpp)

all: $(NAME)

$(NAME): $(SRCS)
	@$(CXX) $(CXXFLAGS) $(SRCS) -I. -o $(NAME)

fclean:
	@rm -rf $(NAME)

re: fclean all

clr:
	@clear

e: clr re clr
	@./$(NAME)

.PHONY: all fclean re e cls