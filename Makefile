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
INCS_PATH	= include/ libft/
BUILD_DIR	:= build/
LIBFT_DIR	:= libft/

# ------------------------------------------------------ FILES

SRCS		= $(addprefix $(SRCS_PATH), main.c \
			lst_utils.c \
			stack_format.c \
			validation.c)
SRCS_BONUS	= $(addprefix $(SRCS_PATH),)
LIBFT		= $(addprefix $(LIBFT_DIR), libft.a)
OBJS		= $(SRCS:%.c=$(BUILD_DIR)%.o)
OBJS_BONUS	= $(SRCS_BONUS:%.c=$(BUILD_DIR)%.o)
DEPS		= $(OBJS:.o=.d)
DEPS_BONUS	= $(OBJS_BONUS:.o=.d)

# ------------------------------------------------------ COMMANDS

MKDIR	:= mkdir -p
RM		:= rm -rf
SLEEP	= sleep 0.1
CC		= cc

# ------------------------------------------------------ FLAGS

CFLAGS		= -Wall -Wextra -Werror
DFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
CPPFLAGS	= $(addprefix -I ,$(INCS_PATH)) -MMD -MP
LDLIBS		= $(LIBFT_DIR)libft.a
LDFLAGS		= -ldl -lglfw -pthread

# ------------------------------------------------------ COMPILATION

COMP_OBJ	= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE	= $(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

# ------------------------------------------------------ DEFINE

ifdef WITH_BONUS
	OBJS		:= $(OBJS_BONUS)
	NAME_SERVER	:= $(NAME_BONUS)
	DEPS		:= $(DEPS_BONUS)
endif

# ------------------------------------------------------ FUNCTIONS

define create_dir
	$(MKDIR) $(dir $@)
endef

define bonus
	$(MAKE) WITH_BONUS=TRUE
endef

define comp_objs
	$(COMP_OBJ)
endef

define comp_libft
	printf "$(RED)Building libft files\n$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)
endef

define comp_exe
	$(COMP_EXE)
	# printf "\n"
	printf "$(CYAN)PUSH_SWAP-> $(RESET)$(PURPLE)Ok!\n$(RESET)"
endef

# ------------------------------------------------------ TARGETS

all: $(LIBFT) $(NAME)

$(BUILD_DIR)%.o: %.c
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(OBJS)
	$(call comp_exe)

$(LIBFT):
	$(call comp_libft)

bonus:
	$(call bonus)

clean:
	$(RM) $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEPS)
