LINKER			= gcc -g3
COMPILER		= $(LINKER) -c 

REMOVE			= rm
REMOVE_FORCE		= $(REMOVE) -rf
MAKE_DIR		= mkdir -p

ifdef GDB
COMPILER	+= -g3
endif

DEBUG			= gdb -q -tui
VAL_MEMCHECK		= valgrind

FLAG			= -Wall -Wextra -Werror
FLAG_LEAK		= --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=readline.supp -s

PATH_INCL		= incl
PATH_SRC		= src
PATH_OBJ		= obj
PATH_LIBFT		= lib
PATH_TESTS		= tests

SEARCH_INCL		= -I. -I$(PATH_INCL) -I$(PATH_LIBFT)

MAIN			= $(PATH_SRC)/main_dev.c
FILE_SRC		= $(filter-out $(MAIN), $(wildcard $(PATH_SRC)/*.c))
FILE_HEADER		= $(PATH_INCL)/minishell.h
FILE_OBJ		= $(FILE_SRC:$(PATH_SRC)/%.c=$(PATH_OBJ)/%.o)
LINK_READLINE		= -lreadline

LIBFT			= $(PATH_LIBFT)/libft.a

NAME			= minishell
DEV			= dev

all: $(NAME)

$(NAME): $(LIBFT) $(PATH_OBJ) $(FILE_OBJ) $(FILE_HEADER)
	@$(LINKER) $(FLAG) $(FILE_OBJ) $(LIBFT) $(LINK_READLINE) -o $@
	@echo "Compile cheapshell -> OK"

$(PATH_OBJ):
	@$(MAKE_DIR) $(PATH_OBJ)

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.c $(FILE_HEADER)
	@$(COMPILER) $(FLAG) $(SEARCH_INCL) $< -o $@

clean: $(LIBFT_CLEAN)
	@$(REMOVE_FORCE) $(PATH_OBJ)
	@echo "Clean objects -> OK"

fclean: clean
	@$(REMOVE_FORCE) $(NAME) $(DEV)
	@$(MAKE) -C $(PATH_LIBFT) fclean
	@echo "Fclean project -> OK"

re: fclean all

run: all
	./$(NAME)

debug: all
	$(DEBUG) ./$(NAME)

leak:
	$(VAL_MEMCHECK) $(FLAG_LEAK) ./$(NAME)

test: all
	@$(MAKE) -C $(PATH_TESTS) all
	@echo "Compiling libft -> OK"

dev:
	$(MAKE) -f Makefile_dev

$(LIBFT):
	@$(MAKE) -C $(PATH_LIBFT) all
	@echo "Compiling libft -> OK"

$(LIBFT_CLEAN):
	@$(MAKE) -C $(PATH_LIBFT) clean
	@echo "Cleaning libft -> OK"

$(LIBFT_FCLEAN):
	@$(MAKE) -C $(PATH_LIBFT) fclean
	@echo "Fcleaning libft -> OK" 

.PHONY: all fclean clean re run leak test debug
