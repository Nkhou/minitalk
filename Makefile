CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRC = \
		client.c\
		server.c
SRC_bonus = \
		client_bonus.c\
		server_bonus.c
OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_bonus:.c=.o)

all: server client
bonus: client_bonus server_bonus

server:	server.o libft/libft.a
		$(CC) -o $@ $< libft/libft.a
client:	client.o libft/libft.a
		$(CC) -o $@ $< libft/libft.a

server_bonus:	server_bonus.o libft/libft.a
		$(CC) -o $@ $< libft/libft.a
client_bonus:	client_bonus.o libft/libft.a
		$(CC) -o $@ $< libft/libft.a

%.o	: %.c
		$(CC) $(CFLAGS) -c $< -o $@

libft/libft.a: 
		make -C libft
clean : 
		rm -f $(OBJS) $(OBJS_BONUS)
		make -C libft clean
fclean : clean
		rm -f client server client_bonus server_bonus libft/libft.a

re : fclean all

.PHONY : all clean fclean re