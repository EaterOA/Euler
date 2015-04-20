.file "euler001.s"
.text
    .global _start

.type _start, @function
_start:
    xorq %rcx,%rcx
    xorq %rdi,%rdi
_start_loop1:
    cmpq $0x3e8, %rcx
    jge _start_loop1end
    movq %rcx, %rax
    xorq %rdx, %rdx
    movq $0x3, %r8
    divq %r8
    testq %rdx, %rdx
    jz _start_if1
    movq %rcx, %rax
    xorq %rdx, %rdx
    movq $0x5, %r8
    div %r8
    testq %rdx, %rdx
    jz _start_if1
    jmp _start_if1end
_start_if1:
    addq %rcx, %rdi
_start_if1end:
    incq %rcx
    jmp _start_loop1
_start_loop1end:
    call print_int
    call print_eol
    movq $0x3c, %rax
    movq $0x0, %rdi
    syscall

.type print_eol, @function
print_eol:
    movq $0x1, %rax
    movq $0x1, %rdi
    movq $eol, %rsi
    movq $0x1, %rdx
    syscall
    ret

.type print_int, @function
print_int:
    pushq %rbp
    movq %rsp, %rbp
    pushq %rbx
    subq $0x10, %rsp
    movq %rdi, %rax
    xorq %rbx, %rbx
    movq $0xa, %rdi
print_int_loop1:
    testq %rax, %rax
    jz print_int_loop1end
    xorq %rdx, %rdx
    divq %rdi
    addb $0x30, %dl
    movb %dl, -0x10(%rbp,%rbx,)
    incq %rbx
    jmp print_int_loop1
print_int_loop1end:
    leaq -0x10(%rbp), %rdi
    movq %rbx, %rsi
    call reverse_str
    movq $0x1, %rax
    movq $0x1, %rdi
    leaq -0x10(%rbp), %rsi
    movq %rbx, %rdx
    syscall
    movq -0x8(%rbp), %rbx
    leave
    ret

.type reverse_str, @function
reverse_str:
    decq %rsi
    xorq %rdx, %rdx
reverse_str_loop1:
    cmpq %rsi, %rdx
    jge reverse_str_loop1end
    movb (%rdi,%rsi,), %cl
    xchgb (%rdi,%rdx,), %cl
    movb %cl, (%rdi,%rsi,)
    incq %rdx
    decq %rsi
    jmp reverse_str_loop1
reverse_str_loop1end:
    ret

.align 8
.data
    eol: .ascii "\n"
