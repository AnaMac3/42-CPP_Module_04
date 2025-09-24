NAME = materia

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

DIR_INCLUDES = ./includes
INCLUDES = $(DIR_INCLUDES)/AMateria.hpp \
							Ice.hpp \
							Cure.hpp

DIR_SRCS = ./srcs
SRCS_FILES = $(DIR_SRCS)/AMateria.cpp \
					Ice.cpp \
					Cure.cpp \
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
