# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 14:12:23 by khatlas           #+#    #+#              #
#    Updated: 2022/06/26 15:41:50 by khatlas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*-
#WIP

LDIR 	=	../libft/
LNAME	=	../libft/libft.a
NAME 	=	libftprintf.a
FUNCTS	=	ft_itoa_base_u.c ft_printf.c ft_parse.c ft_parse_x.c ft_format_i.c \
			ft_parse_u.c ft_parse_s.c ft_parse_pp.c ft_parse_p.c ft_parse_i.c \
			ft_parse_c.c ft_format_c.c ft_format_x.c ft_format_s.c \
			ft_format_pp.c
OBJ_PATH =	obj
OBJS	=	$(addprefix $(OBJ_PATH)/,$(FUNCTS:.c=.o))
LIBFT	=	$(addprefix $(LDIR),$(LNAME))
CC 		= 	cc
ARCC 	= 	ar -rcs
CFLAGS 	= 	-Wall -Wextra -Werror
IFLAGS	=	-I ../includes/
RM 		= 	/bin/rm -rf

all: $(NAME)

$(OBJ_PATH) :
	mkdir $(OBJ_PATH)

$(OBJ_PATH)/%o:%c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $(IFLAGS) $< -o $@

$(NAME): $(OBJ_PATH) $(OBJS)
	make -C $(LDIR)
	$(ARCC) $@ $(OBJS) $(LNAME) 

clean:
	@make clean -C $(LDIR)
	@$(RM) $(OBJ_PATH)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LDIR)

re: fclean all

.PHONY: all clean fclean re
