LINKER		= gcc
COMPILER	= $(LINKER) -c
FLAGS		= -Wall -Wextra -Werror

REMOVE		= rm
REMOVE_FORCE	= $(REMOVE) -rf

ifdef GDB
COMPILER	+= -g3
endif

# DIRECTORIES
SRC		= ../src
TEST		= ../tests
INCL		= ../lib

# UNIT DIRECTORIES
UNITY		= ../tests/Unity/src
FIXTURE		= ../tests/Unity/extras/fixture/src
MEMUNI		= ../tests/Unity/extras/memory/src

# FILES
PATH_INCL	= -I. -I$(INCL) -I$(UNITY) -I$(FIXTURE) -I$(MEMUNI) 
HEADER		= tests.h
HEADER_UNIT	= $(UNITY)/unity.h
HEADER_FIXTURE	= $(FIXTURE)/unity_fixture.h

FILE_SRC	= $(filter-out $(SRC)/minishell.c,  $(wildcard $(SRC)/*c))
FILE_SRC	+= $(wildcard $(TEST)/*c)

# FILE_SRC	+= $(subst main.c, tests.c, $(FILE_SRC))
FILE_OBJ	= $(FILE_SRC:%.c=%.o)

FILE_UNITY	= $(UNITY)/unity.c 
FILE_FIXTURE	= $(FIXTURE)/unity_fixture.c 
 
NAME		= tester 
LIBFT		= ../lib/libft.a

all: $(NAME)

$(NAME): $(FILE_OBJ) $(HEADER) $(HEADER_UNIT) $(HEADER_FIXTURE)
	$(LINKER) $(FLAGS) $(FILE_UNITY) $(FILE_FIXTURE) $(FILE_OBJ) $(PATH_INCL) $(LIBFT) -lreadline -o $@

%.o: %.c $(HEADER) $(HEADER_UNIT) $(HEADER_FIXTURE)
	$(COMPILER) $(PATH_INCL) $< -o $@

clean:
	$(REMOVE_FORCE) $(FILE_OBJ)

fclean: clean
	$(REMOVE_FORCE) $(NAME)

re: fclean all

debug:
	gdb -tui -q $(NAME)

test: all clean
	./$(NAME)

.PHONY: all clean fclean re debug test
