# ----------------------------------------------------- COLORS

CYAN	= \033[0;36m
PURPLE	= \033[0;35m
YELLOW	= \033[33m
GREEN	= \033[0;32m
WHITE	= \033[37m
RED		= \033[31m
RESET	= \033[0m

# ------------------------------------------------------ NAME

NAME			= push_swap
.DEFAULT_GOAL	:= all
.PHONY: all clean fclean re bonus
.SILENT:

# ------------------------------------------------------ PATH

SRCS_PATH	= src/
INCS_PATH	= -Iinclude/ -Ilibft/
BUILD_DIR	:= build/
LIBFT_DIR	:= ./libft/

# ------------------------------------------------------ FILES

SRC		= $(addprefix $(SRCS_PATH), \
			./init/main.c \
			./init/validation.c \
			./init/process_args.c \
			./moves/swap.c \
			./moves/push.c \
			./moves/reverse_rotate.c \
			./moves/rotate.c \
			./algorithm/algorithm_2-3.c \
			./algorithm/algorithm_4-5.c \
			./algorithm/algorithm_big.c \
			./algorithm/define_moves.c \
			./algorithm/execute.c \
			./algorithm/find_position.c \
			./utils/ft_utils.c \
			./utils/init.c \
			./utils/list.c)
LIBFT	:= $(LIBFT_DIR)libft.a
OBJS	= $(SRC:%.c=$(BUILD_DIR)%.o)

# ------------------------------------------------------ BONUS FILES

NAME_BONUS		= checker
SRCS_BONUS	= $(addprefix $(SRCS_PATH),\
			./init/validation.c \
			./init/process_args.c \
			./moves/swap.c \
			./moves/push.c \
			./moves/reverse_rotate.c \
			./moves/rotate.c \
			./algorithm/algorithm_2-3.c \
			./algorithm/algorithm_4-5.c \
			./algorithm/algorithm_big.c \
			./algorithm/define_moves.c \
			./algorithm/execute.c \
			./algorithm/find_position.c \
			./utils/ft_utils.c \
			./utils/init.c \
			./utils/list.c \
			./bonus/checker.c \
			./bonus/utils.c)

OBJS_BONUS		= ${SRCS_BONUS:%.c=$(BUILD_DIR)%.o}

ifdef WITH_BONUS
	NAME		= $(NAME_BONUS)
	SRCS		= $(SRCS_BONUS)
	OBJS		= $(OBJS_BONUS)
endif

# ------------------------------------------------------ COMMANDS

MKDIR	:= mkdir -p
RM		:= rm -rf
CC		= cc

# ------------------------------------------------------ FLAGS

CFLAGS		= -Wall -Wextra -Werror -g3
CPPFLAGS	= $(INCS_PATH) -MMD -MP
LDFLAGS		= -ldl -lglfw -pthread

# ------------------------------------------------------ COMPILATION

COMP_OBJ	= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE	= $(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# ------------------------------------------------------ FUNCTIONS

define create_dir
	$(MKDIR) $(dir $@)
endef

define comp_objs
	$(call create_dir)
	$(COMP_OBJ)
endef

define comp_libft
	printf "$(RED)Building libft files\n$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)
endef

define comp_exe
	$(COMP_EXE)
	printf "$(CYAN)PUSH_SWAP-> $(RESET)$(PURPLE)is ready!\n$(RESET)"
endef

# ------------------------------------------------------ TARGETS

gdb:
	$(CC) $(DFLAGS) $(CPPFLAGS) -c $< -o $@
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(call comp_exe)

$(LIBFT):
	$(call comp_libft)

$(BUILD_DIR)%.o: %.c
	$(call comp_objs)

bonus:
	@echo "$(CYAN)Compiling the checker!!$(RESET)"
	$(MAKE) WITH_BONUS=TRUE

clean:
	$(RM) $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	printf "$(CYAN)PUSH_SWAP $(DARK_GREEN)was cleaned up\n$(RESET)"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	printf "$(CYAN)Executable push_swap $(DARK_GREEN)was deleted\n$(RESET)"

re: fclean all
