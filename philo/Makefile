CC=gcc
C_FLAGS=-Wall -Wextra -Werror
NAME=philo
SRC_DIR=./sources/
OBJ_DIR=./objects/
SRC_LIST=philo_main.c
SRC=$(addprefix $(SRC_DIR), $(SRC_LIST))
OBJ=$(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRC_LIST)))
HEADER=./includes/philo.h
GREEN=\033[0;32m
RED = \033[0;31m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER)
	@$(CC) $(C_FLAGS) $(OBJ) -o $@
	@echo "\n$(GREEN)creating: $(NAME)"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@echo "$(GREEN)creating: object-files: \c"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(C_FLAGS) $^ -c -o $@
	@echo "$(GREEN).\c"

clean:
	@rm -f $(OBJ)
	@rm -f -d $(OBJ_DIR)
	@echo "$(RED)deleting: object-files"

fclean:
	@make clean
	@rm -f $(NAME)
	@echo "$(RED)deleting: $(NAME)"

re:
	@make fclean
	@make $(NAME)