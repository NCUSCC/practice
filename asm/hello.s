.global _start

.section .data
hello:
    .ascii "Hello, World!\n"

.section .text
_start:
    mov x0, 1                // 文件描述符 (stdout)
    ldr x1, =hello           // 字符串地址
    mov x2, 13               // 字符串长度
    mov x8, 64               // 系统调用号 (sys_write)
    svc 0                    // 发起系统调用

    mov x8, 93               // 系统调用号 (sys_exit)
    mov x0, 0                // 返回码
    svc 0                    // 发起系统调用
