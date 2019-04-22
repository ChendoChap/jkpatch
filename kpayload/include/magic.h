/* golden */
/* 1/2/2018 */

 // inspired by fail0verflow, of course
 // 4.55

 // ref FFFFFFFF8F59C000

#define __Xfast_syscall							0x3095D0
#define __copyin								0x14A890
#define __copyout								0x14A7B0
#define __printf								0x017F30
#define __vprintf                               0x017FA0
#define __malloc								0x3F7750
#define __free									0x3F7930
#define __memcpy								0x14A6B0
#define __memset								0x302BD0
#define __memcmp								0x242A60
#define __kmem_alloc							0x16ECD0
#define __strlen                                0x3514F0
#define __pause									0x261120
#define __kthread_add							0x464C90
#define __kthread_exit							0x464F60
#define __sched_prio							0x072410
#define __sched_add								0x072740
#define __kern_yield							0x261440
#define __fill_regs								0x2829C0
#define __set_regs								0x282AF0
#define __create_thread							0x2ECCD0
#define __kproc_create							0x464700
#define __kthread_set_affinity					0x4655E0
#define __kthread_suspend_check					0x465380
#define __kproc_kthread_add						0x465490
#define __sx_init_flags							0x38F900
#define __sx_xlock								0x38FA30
#define __sx_xunlock							0x38FBC0
#define __mtx_init								0x30E0C0
#define __mtx_lock_spin_flags					0x30DA70
#define __mtx_unlock_spin_flags					0x30DC30
#define __mtx_lock_flags						0x30D6A0
#define __mtx_unlock_flags						0x30D940
#define __fpu_kern_enter						0x059580
#define __fpu_kern_leave						0x059680
#define __kern_reboot							0x0998A0
#define __vm_map_lock_read						0x3920B0
#define __vm_map_lookup_entry					0x392C70
#define __vm_map_unlock_read					0x392100
#define __vmspace_free							0x391D10
#define __vm_map_delete							0x394790
#define __vm_map_protect						0x396860
#define __vmspace_acquire_ref					0x391EE0
#define __vm_map_findspace						0x394E90
#define __vm_map_insert							0x392F70
#define __vm_map_lock							0x391F40
#define __vm_map_unlock 						0x391FB0
#define __proc_rwmem							0x17CB70

#define __disable_console_output        0x1997BC8
#define __M_TEMP					   	0x1993B30
#define __kernel_map                    0x1B31218
#define __prison0                       0x10399B0
#define __rootvnode                     0x21AFA30
#define __allproc						0x1AD7718