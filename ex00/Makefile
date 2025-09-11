NAME = fixed

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Fixed.cpp \
		main.cpp \

INCLUDES = Fixed.hpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -c $(NAME) -o $(OBJ)

%.o: %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

make re: fclean all

.PHONY: all clean fclean re
