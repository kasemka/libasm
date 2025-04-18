global ft_strcpy

ft_strcpy:
   mov rax, 0                  ; rax will store the index of the array while we iterate through it
 
loop:
  mov cl, byte [rsi+rax]       ; copy a byte from source array to cl register
  mov byte [rdi+rax], cl       ; copy a byte from cl register to destination rdi
  cmp byte cl, 0               ; check if byte is nullterm
  je return                    ; if nullterm, jump to return
  inc rax                      ; else increase index
  jmp loop                     ; continue looping

return:
  mov rax, rdi                 ; copy new array from rdi to rax
  ret                          ; return rax
