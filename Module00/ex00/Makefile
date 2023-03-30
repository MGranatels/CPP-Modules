# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 14:55:38 by mgranate          #+#    #+#              #
#    Updated: 2023/03/24 15:18:13 by mgranate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	megaphone

CP			=	c++

SRCS		=	megaphone.cpp

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