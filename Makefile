# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcherki <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 17:09:55 by mcherki           #+#    #+#              #
#    Updated: 2022/03/05 17:09:58 by mcherki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
INC = minitalk.h
UTILS = nbr_str.c

C_SRC = client.c
C_OBJ = ${C_SRC:.c=.o}

S_SRC = server.c
S_OBJ = ${S_SRC:.c=.o}

C_NAME = client
S_NAME = server

B_SERVER = server_bonus.c
B_CLIENT = client_bonus.c 

all: $(C_NAME) $(S_NAME)

$(C_NAME): $(C_OBJ) $(INC)
	$(CC) $(CFLAGS) $(C_OBJ) $(UTILS) -o $(C_NAME)
$(S_NAME): $(S_OBJ) $(INC)
	$(CC) $(CFLAGS) $(S_OBJ) $(UTILS) -o $(S_NAME)

clean:
	$(RM) $(S_OBJ) $(C_OBJ)

fclean: clean
	$(RM) $(C_NAME) $(S_NAME)

bonus: $(B_CLIENT) $(B_SERVER)
	$(CC) $(CFLAGS)  $(B_CLIENT) $(UTILS) -o $(C_NAME)
	$(CC) $(CFLAGS) $(B_SERVER) $(UTILS) -o $(S_NAME)

re: fclean all