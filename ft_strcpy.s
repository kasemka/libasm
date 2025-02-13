global ft_strcpy

ft_strcpy:
   mov rax, 0
 
loop:
  mov cl, byte [rsi+rax]
  mov byte [rdi+rax], cl
  cmp byte cl, 0
  je return
  inc rax
  jmp loop

return:
  mov rax, rdi  
  ret 
