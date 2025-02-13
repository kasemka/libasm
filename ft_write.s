SYS_WRITE equ 1

extern __errno_location
global ft_write

ft_write:
  mov rax, SYS_WRITE
  syscall
  cmp rax, 0
  jl set_error
  ret

set_error:
  mov rdi, rax
  call	__errno_location wrt ..plt
  neg rdi
  mov [rax], rdi
  mov rax, -1
  ret


