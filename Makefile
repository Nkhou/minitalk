CC = gcc 
CFLAGS = -Wall -Wextra -Werror
SRC = client.c\
		server.c

OBJS = $(SRC:.c=.o)

all: server client

server:	server.o libft/libft.a
		$(CC) -o $@ $< -Libft 

client:	client.o libft/libft.a
		$(CC) -o $@ $< -Libft

%.o	: %.c
		$(CC) $(CFLAGS) -c $< -o $@

libft/libft.a: 
		make -C libft

clean : 
		rm -f $(OBJS)
		make -C libft clean

fclean : clean
		rm -f client server libft/libft.a

re : fclean all

.PHONY : all clean fclean re libft