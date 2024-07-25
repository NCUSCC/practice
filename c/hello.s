.arch armv8-a               // 指定目标架构为 ARMv8-A
.file	"hello.c"           // 标识源文件的名称
.text                       // 开始代码段
.section	.rodata         // 定义只读数据段，存放常量数据，如字符串
.align	3                  // 对齐到 8 字节（2^3），提高访问效率
.LC0:                       // 局部标签，用于标识常量字符串的位置
	.string	"Hello, World!"  // 定义一个字符串常量
.text                       // 再次声明代码段
.align	2                  // 对齐到 4 字节（2^2）
.global	main                // 定义全局符号 main，使其可被链接器识别
.type	main, %function     // 声明 main 的类型为函数

main:
.LFB0:                      // 开始函数 main 的帧信息块
	.cfi_startproc         // 开始函数的 CFI（Call Frame Information）信息
	stp	x29, x30, [sp, -16]! // 保存帧指针（x29）和返回地址（x30），并调整栈指针
	.cfi_def_cfa_offset 16 // 定义 CFA（Canonical Frame Address）偏移量
	.cfi_offset 29, -16    // CFI: 保存 x29 的偏移量
	.cfi_offset 30, -8     // CFI: 保存 x30 的偏移量
	mov	x29, sp             // 设置新的帧指针
	adrp	x0, .LC0          // 加载常量字符串的页面地址到 x0 寄存器
	add	x0, x0, :lo12:.LC0  // 加上页内偏移，获取字符串的完整地址
	bl	puts                // 调用 puts 函数，输出字符串
	mov	w0, 0               // 设置返回值为 0
	ldp	x29, x30, [sp], 16  // 恢复帧指针和返回地址，恢复栈指针
	.cfi_restore 30        // CFI: 恢复 x30
	.cfi_restore 29        // CFI: 恢复 x29
	.cfi_def_cfa_offset 0  // CFI: 设置 CFA 偏移量为 0
	ret                    // 返回到调用者
	.cfi_endproc           // 结束函数的 CFI 信息
.LFE0:                      // 结束函数 main 的帧信息块
	.size	main, .-main     // 定义函数 main 的大小
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0" // 编译器标识
	.section	.note.GNU-stack,"",@progbits // 指示不需要可执行栈