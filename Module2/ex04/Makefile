# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 14:55:38 by mgranate          #+#    #+#              #
#    Updated: 2023/03/27 21:16:08 by mgranate_ls      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Replace

CP			=	c++

SRCS		=	Replace.cpp \
				main.cpp

CFLAGS		=	-Wall -Wextra -Werror -g -std=c++98 #-fsanitize=address

RM			=	rm -f

OBJS		=	$(SRCS:%.cpp=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CP) $(SRCS) $(CFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re