# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 15:03:37 by yustinov          #+#    #+#              #
#    Updated: 2024/09/28 15:11:25 by yustinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source Files
SRC_DIR = .
HANDLER_DIR = ft_handlers
HELPER_DIR = ft_helpers

SRC = $(SRC_DIR)/ft_config.c \
      $(SRC_DIR)/ft_handler.c \
      $(SRC_DIR)/ft_parse_convertion.c \
      $(SRC_DIR)/ft_printf.c \
      $(HANDLER_DIR)/ft_handle_addr.c \
      $(HANDLER_DIR)/ft_handle_char.c \
      $(HANDLER_DIR)/ft_handle_hex.c \
      $(HANDLER_DIR)/ft_handle_int.c \
      $(HANDLER_DIR)/ft_handle_str.c \
      $(HANDLER_DIR)/ft_handle_uint.c \
      $(HELPER_DIR)/ft_hexform.c \
      $(HELPER_DIR)/ft_numbers.c \
      $(HELPER_DIR)/ft_strings.c \
      $(HELPER_DIR)/ft_writing.c

# Object files
OBJ = $(SRC:.c=.o)

# Targets
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

