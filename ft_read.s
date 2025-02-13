SYS_READ equ 0

extern __errno_location
global ft_read

ft_read:
  mov rax, SYS_READ
  syscall
  cmp rax, 0
  jl set_error
  ret

set_error:
  mov rdi, rax
  call __errno_location wrt ..plt
  neg rdi
  mov [rax], rdi
  mov rax, -1
  ret

