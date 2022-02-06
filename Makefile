# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 12:42:12 by ayassir           #+#    #+#              #
#    Updated: 2022/01/18 19:45:21 by ayassir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT	=	client
SERVER	=	server
CLIENTB	=	client_bonus
SERVERB	=	server_bonus

PRINTF		=	ft_printf/libftprintf.a
PRINTF_DIR	=	ft_printf/
HEADER		= 	minitalk.h

SRC_C	=	client.c
SRC_S	=	server.c
SRCB_C	=	client_bonus.c
SRCB_S	=	server_bonus.c

CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -f

red			=	`tput setaf 1`
green		=	`tput setaf 2`
white		=	`tput setaf 7`

all: $(SERVER) $(CLIENT) $(SERVERB) $(CLIENTB)

$(SERVER): $(PRINTF) $(HEADER) $(SRC_S)
	@ $(CC) $(CFLAG) $(SRC_S) $(PRINTF) -o $(SERVER) 
	@echo " [$(green)SUCCESS$(white)] server $(green)ready$(white)."

$(CLIENT): $(PRINTF) $(HEADER) $(SRC_C)
	@ $(CC) $(CFLAG) $(SRC_C) $(PRINTF) -o $(CLIENT)
	@echo " [$(green)SUCCESS$(white)] client $(green)ready$(white)."

$(SERVERB): $(PRINTF) $(HEADER) $(SRCB_S)
	@ $(CC) $(CFLAG) $(SRCB_S) $(PRINTF) -o $(SERVERB)
	@echo " [$(green)SUCCESS$(white)] server_bonus $(green)ready$(white)."

$(CLIENTB): $(PRINTF) $(HEADER) $(SRCB_C)
	@ $(CC) $(CFLAG) $(SRCB_C) $(PRINTF) -o $(CLIENTB)
	@echo " [$(green)SUCCESS$(white)] client_bonus $(green)ready$(white)."

$(PRINTF):
	@ $(MAKE) -C $(PRINTF_DIR)

clean:
	@ $(RM) $(CLIENT) $(SERVER)
	@echo " [$(red)INFO$(white)] client $(red)removed$(white)."
	@echo " [$(red)INFO$(white)] server $(red)removed$(white)."
	@ $(RM) $(CLIENTB) $(SERVERB)
	@echo " [$(red)INFO$(white)] client_bonus $(red)removed$(white)."
	@echo " [$(red)INFO$(white)] server_bonus $(red)removed$(white)."	

fclean:
	@ $(MAKE) fclean -C $(PRINTF_DIR)
	@echo " [$(red)INFO$(white)] object files $(red)removed$(white)."
	@ $(RM) $(CLIENT) $(SERVER)
	@echo " [$(red)INFO$(white)] client $(red)removed$(white)."
	@echo " [$(red)INFO$(white)] server $(red)removed$(white)."
	@ $(RM) $(CLIENTB) $(SERVERB)
	@echo " [$(red)INFO$(white)] client_bonus $(red)removed$(white)."
	@echo " [$(red)INFO$(white)] server_bonus $(red)removed$(white)."	
re: fclean all

mandatory:	$(CLIENT) $(SERVER)
bonus:		$(CLIENTB) $(SERVERB)

m : mandatory
b : bonus

.PHONY: all clean fclean re mandatory m bonus b
