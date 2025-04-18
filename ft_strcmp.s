global ft_strcmp

ft_strcmp:
  mov rcx, 0                     ; init counter

loop:
  mov al, byte [rdi+rcx]         ; save one byte from str1 to al
  mov bl, byte [rsi+rcx]         ; save one byte from str2 to bl
  cmp al, bl                     ; compare bytes in two registers
  jne return                     ; if compared bytes are not equal, jump to return func
  cmp al, 0                      ; chcek if string is null terminated
  je return                      ; if str1 current byte is nullterm, then jump to return func
  inc rcx                        ; increase index
  jmp loop                       ; continue loop

return:
  sub al, bl
  movsx rax, al                  ; extend 8bit al to 64bits and save it in rax
  ret                            ; return rax
