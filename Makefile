LIB_NAME = libasm.a

SRC = ft_strlen.s \
	    ft_strcpy.s \
	    ft_strcmp.s \
	    ft_write.s \
	    ft_read.s \
	    ft_strdup.s

ASM_OBJS = $(SRC:.s=.o)

CC = gcc
ASM = nasm
ASM_FLAGS = -f elf64
CFLAGS = -Wall -Wextra -Werror

all: $(LIB_NAME)

$(LIB_NAME): $(ASM_OBJS)
	 ar rcs $(LIB_NAME) $(ASM_OBJS)

%.o: %.s
	$(ASM) $(ASM_FLAGS) $< -o $@

test :
	$(CC) $(CFLAGS) main.c $(LIB_NAME) -L. -lasm

clean:
	rm -f $(ASM_OBJS) 

fclean: clean
	rm -f $(LIB_NAME) ./a.out

re: fclean all

