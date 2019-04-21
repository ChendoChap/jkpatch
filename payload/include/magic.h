/* golden */
/* 1/2/2018 */

// inspired by fail0verflow, of course
// 4.74

// ref FFFFFFFF8E958000

#define __Xfast_syscall							0x30B7D0
#define __copyin								0x149F20
#define __copyout								0x149E40
#define __printf								0x017F30
#define __malloc								0x3F85C0
#define __free									0x3F87A0
#define __memcpy								0x149D40
#define __memset								0x304DD0
#define __memcmp								0x244EE0
#define __kmem_alloc							0x16DF30
#define __strlen                                0x0353720

#define __disable_console_output                0x199FC18
#define __M_TEMP					        	0x199BB80
#define __kernel_map                            0x1B39218
#define __prison0                               0x1042AB0
#define __rootvnode                             0x21B89E0
