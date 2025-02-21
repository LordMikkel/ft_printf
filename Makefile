# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 00:30:29 by migarrid          #+#    #+#              #
#    Updated: 2025/02/17 23:48:51 by migarrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre de la biblioteca
NAME = libftprintf.a

# Directorios
LIBFT_DIR = libft
SRC_DIR = src
SRC_BONUS_DIR = src_bonus
UTILS_DIR = $(SRC_DIR)/utils
UTILS_BONUS_DIR = $(SRC_BONUS_DIR)/utils
INCLUDE_DIR = includes

# Compilador y opciones
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR)

# Comandos
PRINTF = printf
RM = rm -f

# Colores y formato
DEFAULT = \033[0;39m
GREEN = \033[0;92m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m

# Archivos fuente obligatorios
SRCS =	$(SRC_DIR)/ft_printf.c \
		$(UTILS_DIR)/ft_print_char.c \
		$(UTILS_DIR)/ft_print_str.c \
		$(UTILS_DIR)/ft_print_ptr.c \
		$(UTILS_DIR)/ft_print_num.c \
		$(UTILS_DIR)/ft_print_unsigned.c \
		$(UTILS_DIR)/ft_print_hex.c \
		$(UTILS_DIR)/ft_itoa_base.c \
		$(UTILS_DIR)/ft_utoa.c \

# Objetos obligatorios
OBJS = $(SRCS:.c=.o)

# Archivos fuente bonus
BONUS_SRCS =	$(SRC_BONUS_DIR)/ft_printf_bonus.c \
				$(SRC_BONUS_DIR)/ft_apply_flags_bonus.c \
				$(SRC_BONUS_DIR)/ft_apply_hash_bonus.c \
				$(SRC_BONUS_DIR)/ft_apply_left_align_bonus.c \
				$(SRC_BONUS_DIR)/ft_apply_plus_bonus.c \
				$(SRC_BONUS_DIR)/ft_apply_precision_bonus.c \
				$(SRC_BONUS_DIR)/ft_apply_space_bonus.c \
				$(SRC_BONUS_DIR)/ft_apply_zero_pad_bonus.c \
				$(SRC_BONUS_DIR)/ft_apply_min_width_bonus.c \
				$(UTILS_BONUS_DIR)/ft_print_char_bonus.c \
				$(UTILS_BONUS_DIR)/ft_print_str_bonus.c \
				$(UTILS_BONUS_DIR)/ft_print_ptr_bonus.c \
				$(UTILS_BONUS_DIR)/ft_print_num_bonus.c \
				$(UTILS_BONUS_DIR)/ft_print_unsigned_bonus.c \
				$(UTILS_BONUS_DIR)/ft_print_hex_bonus.c \
				$(UTILS_BONUS_DIR)/ft_itoa_base_bonus.c \
				$(UTILS_BONUS_DIR)/ft_utoa_bonus.c \

# Objetos bonus
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Variables de progreso
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRCS) | wc -w) - $(shell ls -l $(OBJS) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

BONUS_COUNT_TOT := $(shell expr $(shell echo -n $(BONUS_SRCS) | wc -w) - $(shell ls -l $(BONUS_OBJS) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(BONUS_COUNT_TOT) -le 0; echo $$?),0)
	BONUS_COUNT_TOT := $(shell echo -n $(BONUS_SRCS) | wc -w)
endif
BONUS_COUNT := 0
BONUS_PCT = $(shell expr 100 \* $(BONUS_COUNT) / $(BONUS_COUNT_TOT))

# Regla principal: compilar la biblioteca
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a ./$(NAME)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@$(PRINTF) "\r%100s\r$(GREEN) $(NAME) is up to date!$(DEFAULT)\n"

# Regla para compilar archivos bonus .c a .o con barra de progreso
%.o: %.c $(INCLUDE_DIR)/ft_printf.h $(LIBFT_DIR)/libft.h Makefile
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) -c -o $@ $<

# Regla para compilar obligatorios + bonus
bonus: .bonus

.bonus: $(NAME) $(BONUS_OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a ./$(NAME)
	@ar rcs $(NAME) $(BONUS_OBJS)
	@$(PRINTF) "\r%100s\r$(MAGENTA) Bonus $(NAME) is up to date!$(DEFAULT)\n"
	@touch .bonus

# Cómo cada archivo .c a .o (Obligatorio + Bonus)
$(SRC_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c $(INCLUDE_DIR)/ft_printf.h $(LIBFT_DIR)/libft.h Makefile
	@$(eval BONUS_COUNT = $(shell expr $(BONUS_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(MAGENTA)$<$(DEFAULT)..." "" $(BONUS_COUNT) $(BONUS_COUNT_TOT) $(BONUS_PCT)
	@$(CC) $(CFLAGS) -c -o $@ $<

# Realizar test
test: $(NAME) main.c
	@$(PRINTF) "$(CYAN)\n╔════════════════════════════════════════╗$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)║     Iniciando pruebas de ft_printf     ║$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)╚════════════════════════════════════════╝$(DEFAULT)\n\n"
	@$(PRINTF) "$(CYAN)🔧 Compilando tests...$(DEFAULT)\n"
	@$(CC) $(CFLAGS) main.c -o test $(NAME)
	@$(PRINTF) "$(YELLOW)🔍 Ejecutando Valgrind para verificar memoria...$(DEFAULT)\n\n"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test
	@$(PRINTF) "\n$(GREEN)✅ Tests completados!$(DEFAULT)\n"

# Realizar test bonus
testbonus: $(NAME) main.c
	@$(PRINTF) "$(CYAN)\n╔════════════════════════════════════════╗$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)║   Iniciando pruebas de ft_printf bonus ║$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)╚════════════════════════════════════════╝$(DEFAULT)\n\n"
	@$(PRINTF) "$(CYAN)🔧 Compilando tests bonus...$(DEFAULT)\n"
	@$(CC) $(CFLAGS) -DBONUS main.c -o test $(NAME)
	@$(PRINTF) "$(YELLOW)🔍 Ejecutando Valgrind para verificar memoria...$(DEFAULT)\n\n"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test
	@$(PRINTF) "\n$(GREEN)✅ Tests bonus completados!$(DEFAULT)\n"

# Limpiar objetos
clean:
	@$(PRINTF) "$(CYAN)Cleaning up object files...$(DEFAULT)\n"
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS) $(BONUS_OBJS)

# Limpiar todo (Objetos + biblioteca)
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME) .bonus test
	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"

# Recompilar todo desde cero sin bonus
re: fclean all

# Recompilar todo desde cero
rebonus: fclean bonus

#  Asegurar que las reglas se ejecuten como comando del make
.PHONY: all bonus test clean fclean test testbonus re rebonus
