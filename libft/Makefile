# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 19:51:37 by migarrid          #+#    #+#              #
#    Updated: 2025/02/23 22:12:18 by migarrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre de la biblioteca
NAME = libft.a

# Compilador y opciones
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Colores
DEFAULT = \033[0;39m
GREEN = \033[0;92m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m

# Directorios
PRINCIPAL_DIR = principal
BONUS_DIR = bonus

# Comandos
PRINTF = printf
RM = rm -f

# Archivos fuente obligatorios
SRCS =	principal/ft_isalpha.c \
		principal/ft_isdigit.c \
		principal/ft_isalnum.c \
		principal/ft_isascii.c \
		principal/ft_isprint.c \
		principal/ft_strlen.c \
		principal/ft_memset.c \
		principal/ft_bzero.c \
		principal/ft_memcpy.c \
		principal/ft_memmove.c \
		principal/ft_strlcpy.c \
		principal/ft_strlcat.c \
		principal/ft_toupper.c \
		principal/ft_tolower.c \
		principal/ft_strchr.c \
		principal/ft_strrchr.c \
		principal/ft_strncmp.c \
		principal/ft_memchr.c \
		principal/ft_memcmp.c \
		principal/ft_strnstr.c \
		principal/ft_atoi.c \
		principal/ft_calloc.c \
		principal/ft_strdup.c \
		principal/ft_substr.c \
		principal/ft_strjoin.c \
		principal/ft_strtrim.c \
		principal/ft_split.c \
		principal/ft_itoa.c \
		principal/ft_strmapi.c \
		principal/ft_striteri.c \
		principal/ft_putchar_fd.c \
		principal/ft_putstr_fd.c \
		principal/ft_putendl_fd.c \
		principal/ft_putnbr_fd.c


# Archivos fuente bonus
BONUS_SRCS =	bonus/ft_lstnew_bonus.c \
				bonus/ft_lstadd_front_bonus.c \
				bonus/ft_lstsize_bonus.c \
				bonus/ft_lstlast_bonus.c \
				bonus/ft_lstadd_back_bonus.c \
				bonus/ft_lstdelone_bonus.c \
				bonus/ft_lstclear_bonus.c \
				bonus/ft_lstiter_bonus.c \
				bonus/ft_lstmap_bonus.c

# Objetos obligatorios
OBJS = $(SRCS:.c=.o)

# Objetos bonus
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Variables de progreso
SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

BONUS_COUNT_TOT := $(shell echo -n $(BONUS_SRCS) | wc -w)
ifeq ($(shell test $(BONUS_COUNT_TOT) -le 0; echo $$?),0)
	BONUS_COUNT_TOT := $(shell echo -n $(BONUS_SRCS) | wc -w)
endif
BONUS_COUNT := 0
BONUS_PCT = $(shell expr 100 \* $(BONUS_COUNT) / $(BONUS_COUNT_TOT))

# Regla principal: compilar la biblioteca
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@$(PRINTF) "\r%100s\r$(GREEN)$(NAME) is up to date!$(DEFAULT)\n"

# Regla para compilar archivos .c a .o con barra de progreso
$(PRINCIPAL_DIR)/%.o: $(PRINCIPAL_DIR)/%.c libft.h Makefile
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) -c -o $@ $<

# Regla para compilar obligatorios + bonus
bonus: .bonus

# Regla para compilar obligatorios + bonus
.bonus: $(NAME) $(BONUS_OBJS)
	@ar rcs $(NAME) $(BONUS_OBJS)
	@$(PRINTF) "\r%100s\r$(MAGENTA)Bonus $(NAME) is up to date!$(DEFAULT)\n"
	@touch .bonus

# Regla para compilar archivos bonus .c a .o con barra de progreso
$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c libft.h Makefile
	@$(eval BONUS_COUNT = $(shell expr $(BONUS_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(MAGENTA)$<$(DEFAULT)..." "" $(BONUS_COUNT) $(BONUS_COUNT_TOT) $(BONUS_PCT)
	@$(CC) $(CFLAGS) -c -o $@ $<

# Cómo compilar cada archivo .c a .o (tanto obligatorio como bonus)
%.o: %.c libft.h Makefile
	$(CC) $(CFLAGS) -I. -c -o $@ $<

# Limpiar objetos
clean:
	@$(PRINTF) "$(CYAN)Cleaning up object files...$(DEFAULT)\n"
	@$(RM) $(OBJS) $(BONUS_OBJS) .bonus

# Limpiar todo (objetos + biblioteca)
fclean: clean
	@$(RM) $(NAME) test
	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"

# Recompilar todo desde cero sin bonus
re: fclean all

# Recompilar todo desde cero
rebonus: fclean all bonus

# Asegurar que las reglas se ejecuten como comandos del make
.PHONY: all clean fclean re bonus rebonus
