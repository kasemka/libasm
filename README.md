# libasm

A minimal **x86_64 assembly** library re-implementing standard C library functions using **NASM**.  

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

## Build and test

Requirements:

- [`nasm`](https://www.nasm.us/) (Netwide Assembler)
- `gcc` for testing (optional)


Build a library:

```bash
make
```

Test the libasm functions with the provided main.c or you can write you own test:

```bash
make test
./a.out
