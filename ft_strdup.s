global ft_strdup 
extern ft_strlen
extern ft_strcpy
extern malloc
extern __errno_location

ft_strdup:
  mov rbx, rdi
  call ft_strlen
  inc rax
  mov rdi, rax
  call malloc wrt ..plt
  cmp rax, 0
  je set_error
  mov rdi, rax
  mov rsi, rbx
  call ft_strcpy
  ret

set_error:
  mov rdi, rax
  call	__errno_location wrt ..plt
  neg rdi
  mov [rax], rdi
  mov rax, 0
  ret

