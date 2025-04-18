# libasm

A minimal **x86_64 assembly** library re-implementing standard C library functions using **NASM**.  
Great for learning low-level programming and understanding how common C functions work under the hood.

---

## Implemented Functions

| Function     | Description                                        |
|--------------|----------------------------------------------------|
| `ft_strlen`  | Computes the length of a string                    |
| `ft_strcpy`  | Copies a string from source to destination         |
| `ft_strcmp`  | Compares two strings                               |
| `ft_strdup`  | Duplicates a string (uses `malloc`)               |
| `ft_write`   | Writes to a file descriptor (uses `syscall`)      |
| `ft_read`    | Reads from a file descriptor (uses `syscall`)     |

---

## Requirements

- [`nasm`](https://www.nasm.us/) (Netwide Assembler)
- `gcc` for testing (optional)

---

## Testing

You can write your own `main.c` or use the provided sample test cases to verify functionality.

Compile and link your C test with the library:

```bash
gcc -Wall -Wextra -Werror main.c -L. -lasm
