    .text
    .globl  sum_array
    .type   sum_array, @function

# int sum_array(int *arr, long n)
#   %rdi = arr (base address)
#   %rsi = n   (count)
# return:
#   %eax = sum

sum_array:
    xorl    %eax, %eax        # sum = 0
    xorl    %ecx, %ecx        # i = 0

.Lloop:
    cmpq    %rsi, %rcx        # if (i >= n) break
    jge     .Ldone

    addl    (%rdi,%rcx,4), %eax   # sum += arr[i] (int = 4 bytes)
    incq    %rcx                  # i++
    jmp     .Lloop

.Ldone:
    ret

    .section .note.GNU-stack,"",@progbits
