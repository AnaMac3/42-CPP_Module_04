NAME = animal

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

DIR_INCLUDES = ./includes
INCLUDES = $(DIR_INCLUDES)/Animal.hpp \
							Dog.hpp \
							Cat.hpp \
							WrongAnimal.hpp \
							WrongCat.hpp

DIR_SRCS = ./srcs
SRCS_FILES = $(DIR_SRCS)/Animal.cpp \
					Dog.cpp \
					Cat.cpp \
					WrongAnimal.cpp \
					WrongCat.cpp \
					main.cpp

SRCS = $(addprefix $(DIR_SRCS)/, $(SRCS_FILES))

DIR_OBJ = ./obj
OBJ = $(addprefix $(DIR_OBJ)/, $(notdir $(SRCS_FILES:.cpp=.o)))

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(DIR_OBJ)/%.o: $(DIR_SRCS)/%.cpp | $(DIR_OBJ)
		$(CC) $(CFLAGS) -I$(DIR_INCLUDES) -c $< -o $@

$(DIR_OBJ):
	mkdir -p $(DIR_OBJ)

clean:
		@if [ -d $(DIR_OBJ) ]; then rm -rf $(DIR_OBJ); fi

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
