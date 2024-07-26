.arch armv8-a                    ; 指定目标架构为 ARMv8-A
.file   "hello.c"               ; 源文件信息，用于调试和错误追踪

.text                           ; 开始一个代码段
.section .rodata                ; 只读数据段，用于存储字符串常量等不可修改的数据
.align 3                        ; 地址对齐到2^3=8字节
.LC0:                           ; 局部标签，用于字符串的位置标记
    .string "Hello, World!"     ; 定义一个字符串常量

.text                           ; 重新标记代码段
.align 2                        ; 地址对齐到2^2=4字节
.global main                    ; 声明main函数为全局符号，使其可以被其他模块调用
.type   main, %function         ; 声明这是一个函数类型的符号
main:                           ; main函数开始
.LFB0:                          ; 本地函数开始标签
    .cfi_startproc              ; 标记函数的开始，用于调用栈跟踪
    stp     x29, x30, [sp, -16]!; 将帧指针和链接寄存器保存到栈上，并预留栈空间
    .cfi_def_cfa_offset 16      ; 调整当前帧指针偏移
    .cfi_offset 29, -16         ; 保存寄存器x29的偏移
    .cfi_offset 30, -8          ; 保存寄存器x30的偏移
    mov     x29, sp             ; 更新帧指针

    adrp    x0, .LC0            ; 将字符串的地址页对齐部分加载到x0
    add     x0, x0, :lo12:.LC0  ; 将字符串地址的低12位加到x0，形成完整地址
    bl      puts                ; 调用puts函数打印字符串

    mov     w0, 0               ; 将返回值设置为0
    ldp     x29, x30, [sp], 16  ; 恢复x29, x30寄存器的值，并释放栈空间
    .cfi_restore 30             ; 恢复x30寄存器的追踪信息
    .cfi_restore 29             ; 恢复x29寄存器的追踪信息
    .cfi_def_cfa_offset 0       ; 调整当前帧指针偏移
    ret                         ; 返回
    .cfi_endproc                ; 标记函数的结束
.LFE0:                          ; 本地函数结束标签
    .size   main, .-main        ; 指定main函数的大小

.ident  "GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0" ; 编译器版本信息
.section .note.GNU-stack,"",@progbits ; 指定堆栈提示信息