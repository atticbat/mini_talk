# -*- MakeFile -*-

VPATH	=	mandatory helper
SNAME	=	server
CNAME	=	client
SFUNCTS	=	server.c append_buffer.c
CFUNCTS =	client.c
LIBFTNAME =	ft
PTFNAME	=	ftprintf
PTFPATH	=	./ft_printf/
SOBJS	=	$(addprefix $(OBJ_PATH),$(notdir $(SFUNCTS:.c=.o)))
COBJS	=	$(addprefix $(OBJ_PATH),$(notdir $(CFUNCTS:.c=.o)))
CC		=	cc
CFLAGS	= 	-Wall -Werror -Wextra
OBJ_PATH =	./obj/
LIBFTPATH =	./libft/
IFLAGS	=	-I ./includes
RM 		=	/bin/rm -f
RMR		=	/bin/rm -rf
DEPEND	=	-MMD -MP

bonus: all

all: $(SNAME) $(CNAME)

$(OBJ_PATH) :
	mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: %.c | $(OBJ_PATH)
	$(CC) $(CLFAGS) $(IFLAGS) $(DEPEND) -c $< -o $@

$(SNAME) $(CNAME): $(OBJ_PATH) $(SOBJS) $(COBJS)
	make -C $(LIBFTPATH)
	make -C $(PTFPATH)
	$(CC) -o $(SNAME) $(IFLAGS) $(DEPEND) $(SOBJS) -L $(PTFPATH) -l $(PTFNAME) \
		-L $(LIBFTPATH) -l $(LIBFTNAME)
	$(CC) -o $(CNAME) $(IFLAGS) $(DEPEND) $(COBJS) -L $(PTFPATH) -l $(PTFNAME) \
		-L $(LIBFTPATH) -l $(LIBFTNAME)

clean:
	make clean -C $(LIBFTPATH)
	make clean -C $(PTFPATH)
	$(RMR) $(OBJ_PATH)

fclean: clean
	make fclean -C $(LIBFTPATH)
	make fclean -C $(PTFPATH)
	$(RM) $(SNAME)
	$(RM) $(CNAME)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(OBJ_PATH):%.o=%.d
