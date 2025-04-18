global ft_strlen

ft_strlen:
  mov rax, 0                ; will be used as a counter for array iteration

loop:
  cmp byte [rdi+rax], 0     ; check if the byte is null terminated
  je return                 ; if byte is nullterm, jump to return
  inc rax                   ; increase counter
  jmp loop                  ; continue loop
  
return:
  ret                       ; return rax

