.text
    .global _start

.align 4
.func _start
_start:
    xor %eax,%eax
    xor %ebx,%ebx
    xor %ecx,%ecx
_start_loop1:
    cmp $0x3e8, %ebx
    jge _start_loop1end
    movl %ebx, %eax
    xor %edx, %edx
    movl $0x3, %edi
    div %edi
    testl %edx, %edx
    jz _start_if1
    movl %ebx, %eax
    xor %edx, %edx
    movl $0x5, %edi
    div %edi
    testl %edx, %edx
    jz _start_if1
    jmp _start_if1end
_start_if1:
    addl %ebx, %ecx
_start_if1end:
    incl %ebx
    jmp _start_loop1
_start_loop1end:
    pushl %ecx
    call print_int
    call print_eol
    movl $0x1, %eax
    movl $0x0, %ebx
    int $0x80
.endfunc

.func
print_eol:
    pushl %ebx
    movl $0x4, %eax
    movl $0x1, %ebx
    movl $eol, %ecx
    movl $0x1, %edx
    int $0x80
    popl %ebx
    ret
.endfunc

.align 4
.func print_int
print_int:
    pushl %ebp
    movl %esp, %ebp
    pushl %edi
    pushl %ebx
    subl $0x18, %esp
    movl 0x8(%ebp), %eax
    xorl %ebx, %ebx
    movl $0xa, %edi
print_int_loop1:
    testl %eax, %eax
    jz print_int_loop1end
    xorl %edx, %edx
    divl %edi
    addl $0x30, %edx
    movb %dl, -0x18(%ebp,%ebx,)
    incl %ebx
    jmp print_int_loop1
print_int_loop1end:
    leal -0x18(%ebp), %edi
    pushl %ebx
    pushl %edi
    call reverse_str
    movl $0x4, %eax
    leal 0x0(%edi), %ecx
    movl %ebx, %edx
    movl $0x1, %ebx
    int $0x80
    movl -0x4(%ebp), %ebx
    movl -0x8(%ebp), %edi
    leave
    ret
.endfunc

.align 4
.func reverse_str
reverse_str:
    pushl %ebp
    movl %esp, %ebp
    pushl %ebx
    movl 0x8(%ebp), %eax
    movl 0xc(%ebp), %ecx
    decl %ecx
    xor %edx, %edx
reverse_str_loop1:
    cmp %ecx, %edx
    jge reverse_str_loop1end
    movb (%eax,%ecx,), %bl
    xchgb (%eax,%edx,), %bl
    movb %bl, (%eax,%ecx,)
    incl %edx
    decl %ecx
    jmp reverse_str_loop1
reverse_str_loop1end:
    movl -0x4(%ebp), %ebx
    leave
    ret
.endfunc

.align 4
.data
    eol: .ascii "\n"
