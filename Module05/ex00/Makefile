CC			= 	g++ -std=c++98
CFLAGS		= 	-Wall -Wextra -Werror -Wshadow  -g\
				# -fsanitize=address
NAME		= 	bureau
SRCS		=	$(wildcard *.cpp)

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -I. -o $(NAME)

fclean:
	@rm -rf $(NAME)

re: fclean all

clr:
	@clear

e: clr re clr
	@./$(NAME)

.PHONY: all fclean re e cls