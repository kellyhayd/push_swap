# ----------------------------------------------------- COLORS

CYAN		= \033[0;36m
PURPLE		= \033[0;35m
YELLOW		= \033[33m
GREEN		= \033[0;32m
DARK_GREEN	=\033[32m
WHITE		= \033[37m
RED			= \033[31m
DARK_RED	=\033[31m
RESET		= \033[0m

# ------------------------------------------------------ NAME

NAME			= libft.a
.DEFAULT_GOAL	:= all
.PHONY: all clean fclean re
.SILENT:

# ------------------------------------------------------ PATH

SRCS_PATH = src/
BUILD_DIR := build/

# ------------------------------------------------------ FILES

SRCS =	$(addprefix $(SRCS_PATH),\
		ft_arraysize.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_error.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_itoa.c \
		ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_swap.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_printf.c \
		ft_printf_utils.c \
		get_next_line.c \
		get_next_line_utils.c \
		print_hex.c \
		print_char.c \
		print_num.c)
OBJS = $(SRCS:%.c=$(BUILD_DIR)%.o)

# ------------------------------------------------------ COMMAND

MKDIR := mkdir -p
RM := rm -rf
SLEEP = sleep 0.1
CC = cc
AR = ar -rcs

# ------------------------------------------------------ FLAGS

CFLAGS = -Wall -Wextra -Werror
DFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
LDLIBS = -ldl -lglfw -pthread

# ------------------------------------------------------ COMPILATION

COMP_OBJ = $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_LIB = $(AR) $(NAME) $(OBJS)

# ------------------------------------------------------ FUNCTIONS

define create_dir
	$(MKDIR) $(dir $@)
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(COMP_OBJ)
	printf "Compiling Libft$(YELLOW) %d%%\r$(RESET)" $$(echo $$(($(COUNT) * 100 / $(words $(SRCS)))))
endef

define comp_lib
	$(COMP_LIB)
	printf "\n"
	printf "$(CYAN)LIBFT$(RESET)$(PURPLE) is ready to use!\n$(RESET)"
endef

# ------------------------------------------------------ TARGETS

all: $(NAME)

$(BUILD_DIR)%.o: %.c
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(OBJS)
	$(call comp_lib)

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)
	printf "$(CYAN)LIBFT $(DARK_GREEN)was cleaned up\n$(RESET)"

re: fclean all

-include $(DEPS)
