global ft_strdup 
extern ft_strlen
extern ft_strcpy
extern malloc
extern __errno_location

ft_strdup:
  mov rbx, rdi               ; save rdi value in rbx for temperory
  call ft_strlen             ; get lenth of array in rdi
  inc rax                    ; increment the length
  mov rdi, rax               ; copy incremented length to rdi
  call malloc wrt ..plt      ; call malloc, arg = rdi
  cmp rax, 0                 ; check memory allocation result
  je set_error               ; if 0 memory allocated, jump to set_error func
  mov rdi, rax               ; else copy allocated memory address to rdi. rdi will be used as an arg1 in ft_strcpy
  mov rsi, rbx               ; copy array from rbx to rsi. rsi will be used as arg2 in ft_strcpy
  call ft_strcpy             ; call copy function
  ret                        

set_error:
  mov rdi, rax                               
  call	__errno_location wrt ..plt
  neg rdi
  mov [rax], rdi
  mov rax, 0
  ret

