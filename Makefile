NAME= push_swap.a
MAIN= push_swap.c
SRCS= utils.c utils_str.c utils_a.c stack_a_operations.c stack_b_operations.c \
		stack_ab_operations.c sort.c simple_sort.c parsing.c init_stack.c handling_errors.c\
		compl_sort.c manage_groups.c push.c
OBJ= $(SRCS:.c=.o)
INCLUDE= push_swap.h

FLG= -Wall -Wextra -Werror

all: push_swap

push_swap: $(MAIN) $(INCLUDE) $(NAME)
	gcc  $(MAIN) -I $(INCLUDE) $(NAME) -o push_swap
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)


clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME) push_swap


%.o: %.c
	gcc $(FLG) -c $< -I $(INCLUDE)

re: fclean all	
