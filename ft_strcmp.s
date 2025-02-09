global ft_strcmp

ft_strcmp:
  mov rcx, 0                     ; init counter

loop:
  mov al, byte [rdi+rcx]         ; save one byte from str1 to al
  sub al, byte [rsi+rcx]         ; save difference between bytes of al(str1)  and str2 to al
  jnz return                     ; if difference is not equal to 0, then go to return
  cmp byte [rdi+rcx], 0
  je return                      ; else if str1 current byte is nullterm, then go to return
  cmp byte [rsi+rcx], 0
  je return                      ; else if str2 current byte is nullterm, then go to return
  inc rcx
  jmp loop                       ; else continue loop

return:
  movsx rax, al                  ; extend 8bit al to 64bits and save it in rax
  ret                            ; returns rax
