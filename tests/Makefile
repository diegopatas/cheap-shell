LINKER		= gcc
COMPILER	= $(LINKER) -c
FLAG		= -Wall -Wextra -Werror
FLAG_LEAK	= --leak-check=full --show-leak-kinds=all --track-origins=yes -s

VAL_MEMCHECK	= valgrind

REMOVE		= rm
REMOVE_FORCE	= $(REMOVE) -rf

ifdef GDB
COMPILER	+= -g3
endif

# DIRECTORIES
PATH_SRC	= ../src
PATH_INCL	= ../incl
PATH_TEST	= ../tests
PATH_LIBFT	= ../lib
PATH_UNITY	= ../tests/Unity/src
PATH_FIXTURE	= ../tests/Unity/extras/fixture/src
PATH_MEM	= ../tests/Unity/extras/memory/src

# FILES
SEARCH_INCL	= -I. -I$(PATH_INCL) -I$(PATH_LIBFT) -I$(PATH_UNITY) -I$(PATH_FIXTURE) -I$(PATH_MEM) 
HEADER		= tester.h
HEADER_UNIT	= $(PATH_UNITY)/unity.h
HEADER_FIXTURE	= $(PATH_FIXTURE)/unity_fixture.h
HEADER_MEM	= $(PATH_MEM)/unity_memory.h

MAIN		= $(PATH_SRC)/main.c $(PATH_SRC)/main_dev.c
FILE_SRC	= $(filter-out $(MAIN),  $(wildcard $(PATH_SRC)/*c))
FILE_SRC	+= $(wildcard $(PATH_TEST)/*c)
# FILE_SRC	+= $(subst main.c, tests.c, $(FILE_SRC))
FILE_OBJ	= $(FILE_SRC:%.c=%.o)

FILE_UNITY	= $(PATH_UNITY)/unity.c 
FILE_FIXTURE	= $(PATH_FIXTURE)/unity_fixture.c 
FILE_MEM	= $(PATH_MEM)/unity_memory.c
 
NAME		= tester 
LIBFT		= $(PATH_LIBFT)/libft.a
LINK_READLINE	= -lreadline

all: $(NAME)

$(NAME): $(LIBFT) $(FILE_OBJ) $(HEADER) $(HEADER_UNIT) $(HEADER_FIXTURE) $(HEADER_MEM)
	$(LINKER) $(FLAG) $(FILE_UNITY) $(FILE_FIXTURE) $(FILE_MEM) $(FILE_OBJ) $(SEARCH_INCL) $(LIBFT) $(LINK_READLINE) -o $@
	@echo "Compile tester -> OK"

%.o: %.c $(HEADER) $(HEADER_UNIT) $(HEADER_FIXTURE) $(HEADER_MEM)
	$(COMPILER) $(SEARCH_INCL) $< -o $@


clean: $(LIBFT_CLEAN)
	@$(REMOVE_FORCE) $(FILE_OBJ)

fclean: $(LIBFT_FCLEAN) clean
	@$(REMOVE_FORCE) $(NAME)

re: fclean all

debug:
	gdb -tui -q $(NAME)

test: all clean
	./$(NAME)

test_v: all clean
	./$(NAME) -v

leak: all clean
	$(VAL_MEMCHECK) $(FLAG_LEAK) ./$(NAME)

run: all clean
	./$(NAME)

$(LIBFT):
	@$(MAKE) -C $(PATH_LIBFT) all

$(LIBFT_CLEAN):
	@$(MAKE) -C $(PATH_LIBFT) clean

$(LIBFT_FCLEAN):
	@$(MAKE) -C $(PATH_LIBFT) fclean

.PHONY: all clean fclean re debug test
