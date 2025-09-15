NAME = animal

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = Animal.hpp \
			Dog.hpp \
			Cat.hpp \

SRCS = Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		main.cpp \

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(INCLUDES)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

make re: fclean all

.PHONY: all clean fclean re
