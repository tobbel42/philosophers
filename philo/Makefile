CC=gcc
C_FLAGS=-Wall -Wextra -Werror
NAME=philo
SRC_DIR=./sources/
OBJ_DIR=./objects/
SRC_LIST=philo_main.c \
	philo_errors.c \
	philo_init.c \
	philo_routine.c \
	philo_create_threads.c \
	philo_cleanup.c \
	philo_time.c \
	philo_death.c \
	philo_utils.c
SRC=$(addprefix $(SRC_DIR), $(SRC_LIST))
OBJ=$(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRC_LIST)))
HEADER=./includes/philo.h
GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[0;33m
NC=\033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER)
	@$(CC) $(C_FLAGS) $(OBJ) -o $@
	@echo "\n$(GREEN)creating: $(NAME)$(NC)"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@echo "$(GREEN)creating: object-files: $(NC)\c"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(C_FLAGS) $^ -c -o $@
	@echo "$(GREEN).$(NC)\c"

clean:
	@rm -f $(OBJ)
	@rm -f -d $(OBJ_DIR)
	@echo "$(RED)deleting: object-files$(NC)"

fclean:
	@make clean
	@rm -f $(NAME)
	@echo "$(RED)deleting: $(NAME)$(NC)"

re:
	@make fclean
	@make $(NAME)

coffee:
	@echo "\n\n\n  (( (     )(("
	@echo " |====|  |====|"
	@echo "C|    |  |    |D"
	@echo " |____|  |____|"
	@echo "\n"
