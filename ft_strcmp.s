global ft_strcmp

ft_strcmp:
  mov rcx, 0                     ; init counter

loop:
  mov al, byte [rdi+rcx]         ; save one byte from str1 to al
  mov bl, byte [rsi+rcx]         ; save one byte from str2 to bl
  cmp al, bl
  jne return
  cmp al, 0
  je return                      ; else if str1 current byte is nullterm, then go to return
  cmp bl, 0
  je return                      ; else if str2 current byte is nullterm, then go to return
  inc rcx
  jmp loop                       ; else continue loop

return:
  sub al, bl
  movsx rax, al                  ; extend 8bit al to 64bits and save it in rax
  ret                            ; returns rax
