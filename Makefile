# # ----------------------------------------------------- COLORS

# CYAN	= \033[0;36m
# PURPLE	= \033[0;35m
# YELLOW	= \033[33m
# GREEN	= \033[0;32m
# WHITE	= \033[37m
# RED		= \033[31m
# RESET	= \033[0m

# # ------------------------------------------------------ BASIC

# NAME			= push_swap
# .DEFAULT_GOAL	:= all
# .PHONY: all clean fclean re bonus
# # .SILENT:

# # ------------------------------------------------------ PATH

# SRCS_PATH	= src/
# INCS_PATH	= -Iinclude/ -Ilibft/
# BUILD_DIR	:= build/
# LIBFT_DIR	:= libft/

# # ------------------------------------------------------ FILES

# SRCS		= $(addprefix $(SRCS_PATH), \
# 			main.c \
# 			lst_utils.c \
# 			stack_format.c \
# 			validation.c)
# SRCS_BONUS	= $(addprefix $(SRCS_PATH),)
# LIBFT		= $(LIBFT_DIR)libft.a
# OBJS		= $(SRCS:%.c=$(BUILD_DIR)%.o)
# OBJS_BONUS	= $(SRCS_BONUS:%.c=$(BUILD_DIR)%.o)
# DEPS		= $(OBJS:.o=.d)
# DEPS_BONUS	= $(OBJS_BONUS:.o=.d)

# # ------------------------------------------------------ COMMANDS

# MKDIR	:= mkdir -p
# RM		:= rm -rf
# SLEEP	= sleep 0.1
# CC		= cc

# # ------------------------------------------------------ FLAGS

# CFLAGS		= -Wall -Wextra -Werror
# DFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
# CPPFLAGS	= $(addprefix -I ,$(INCS_PATH)) -MMD -MP
# LDLIB		= $(LIBFT_DIR)libft.a
# LDFLAGS		= -ldl -lglfw -pthread

# # ------------------------------------------------------ COMPILATION

# COMP_OBJ	= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
# COMP_EXE	= $(CC) $(LDLIB) $(OBJS) $(LDFLAGS) -o $(NAME)

# # ------------------------------------------------------ DEFINE

# ifdef WITH_BONUS
# 	OBJS	:= $(OBJS_BONUS)
# 	NAME	:= $(NAME_BONUS)
# 	DEPS	:= $(DEPS_BONUS)
# endif

# # ------------------------------------------------------ FUNCTIONS

# define create_dir
# 	$(MKDIR) $(dir $@)
# endef

# define bonus
# 	$(MAKE) WITH_BONUS=TRUE
# endef

# define comp_objs
# 	$(eval COUNT=$(shell expr $(COUNT) + 1))
# 	$(COMP_OBJ)
# 	$(SLEEP)
# 	printf "$(WHITE)Compiling$(FCOLOR)$(YELLOW) PUSH_SWAP: %d%%\r$(FCOLOR)" $$(echo $$(($(COUNT) * 100 / $(words $(SRCS)))))
# 	@if [ $(COUNT) -eq $(words $(SRCS)) ]; then \
# 		printf "$(DARK_GREEN)Push_swap is 100%% compiled$(FCOLOR) ✅"; \
# 		printf "\n"; \
# 	fi
# endef

# define comp_libft
# 	printf "$(RED)Building libft files\n$(RESET)"
# 	$(MAKE) -C $(LIBFT_DIR)
# endef

# define comp_exe
# 	$(COMP_EXE)
# 	printf "$(CYAN)PUSH_SWAP-> $(RESET)$(PURPLE)Ok!\n$(RESET)"
# endef

# # ------------------------------------------------------ TARGETS

# all: $(LIBFT) $(NAME)

# $(BUILD_DIR)%.o: %.c
# 	$(call create_dir)
# 	$(call comp_objs)

# $(NAME): $(OBJS)
# 	$(call comp_exe)

# $(LIBFT):
# 	$(call comp_libft)

# bonus:
# 	$(call bonus)

# clean:
# 	$(RM) $(BUILD_DIR)
# 	$(MAKE) -C $(LIBFT_DIR) clean

# fclean: clean
# 	$(RM) $(NAME)
# 	$(RM) $(NAME_BONUS)
# 	$(MAKE) -C $(LIBFT_DIR) fclean
# 	printf "$(CYAN)PUSH_SWAP$(DARK_GREEN) was $(RED)F$(DARK_GREEN)cleaned up!\n$(RESET)"

# re: fclean all

# -include $(DEPS)



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
			main.c \
			lst_utils.c \
			stack_format.c \
			validation.c)
LIBFT	:= $(LIBFT_DIR)libft.a
OBJS	= $(SRC:%.c=$(BUILD_DIR)%.o)

# ------------------------------------------------------ COMMANDS

MKDIR	:= mkdir -p
RM		:= rm -rf
CC		= cc

# ------------------------------------------------------ FLAGS

CFLAGS		= -Wall -Wextra -Werror -g3
DFLAGS		= -Wall -Wextra -Werror -g3
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



clean:
	$(RM) $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
