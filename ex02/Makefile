# VARIABLE DECLARATION ############################################################################

NAME =			dreamjob

CC =			g++

CFLAGS =		-std=c++98 -Wall -Werror -Wextra

HEADER =		./includes

BLACK	= 		\033[0;30m
RED		= 		\033[0;91m
GREEN	= 		\033[0;92m
YELLOW	= 		\033[0;93m
BLUE	= 		\033[0;94m
PURPLE	= 		\033[0;35m
CYAN	= 		\033[0;96m
WHITE	= 		\033[0;37m

SRCS =			./srcs/tests.cpp \
				./srcs/Account.cpp

OBJS =			$(SRCS:.cpp=.o)

# RULES ###########################################################################################

all: $(NAME)
$(NAME): $(OBJS)
	echo "$(CYAN)Compiling dreamjob :$(WHITE)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	echo "$(GREEN)Dreamjob successfully compiled !$(WHITE)"

./%.o: ./%.cpp $(HEADER)/Account.hpp
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	echo "$(YELLOW)Deleting all files exept binaries$(WHITE)"
	rm -rf $(OBJS)

fclean: clean
	echo "$(PURPLE)Deleting binaries$(WHITE)"
	rm -rf $(NAME)

re:
	make fclean
	make all

.SILENT:

.PHONY: all clean fclean re
