# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: seyildir <seyildir@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/01 19:21:42 by seyildir      #+#    #+#                  #
#    Updated: 2023/02/01 19:21:42 by seyildir      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line.a
HEADER	= get_next_line.h
####################################
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS)
RM		= rm -rf
####################################
AR		= ar
ARFLAGS	= -rc
ARCHIVE	= $(AR) $(ARFLAGS)
####################################
SRC		= get_next_line.c get_next_line_utils.c
OBJ		= $(patsubst %.c,%.o,$(SRC))
####################################
all: $(NAME)

%.o: %.c $(HEADER)
	@echo Compiling: $<
	@gcc -c $< -o $@

$(NAME): $(OBJ)
	@echo Archiving: $(NAME)
	$(ARCHIVE) $(NAME) $(OBJ)

clean:
	@echo Object files deleted.
	@$(RM) $(OBJ)

fclean: clean
	@echo Archive file deleted.
	@$(RM) $(NAME)

re: fclean all
	@echo Remade

arc: all clean
	@echo Archive created
	$(COMPILE) main.c get_next_line.a -o main
	./main