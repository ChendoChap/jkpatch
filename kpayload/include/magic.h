/* golden */
/* 1/2/2018 */

 // inspired by fail0verflow, of course
 // 4.74

 // ref FFFFFFFF96AC4000

#define __Xfast_syscall							0x30B7D0
#define __copyin								0x149F20
#define __copyout								0x149E40
#define __printf								0x017F30
#define __vprintf                               0x017FA0
#define __malloc								0x3F85C0
#define __free									0x3F87A0
#define __memcpy								0x149D40
#define __memset								0x304DD0
#define __memcmp								0x244EE0
#define __kmem_alloc							0x16DF30
#define __strlen                                0x353720
#define __pause									0x2635A0
#define __kthread_add							0x465B20
#define __kthread_exit							0x465DF0
#define __sched_prio							0x0719F0
#define __sched_add								0x071D20
#define __kern_yield							0x2638C0
#define __fill_regs								0x284B70
#define __set_regs								0x284CA0
#define __create_thread							0x2EEED0
#define __kproc_create							0x465590
#define __kthread_set_affinity					0x466470
#define __kthread_suspend_check					0x466210
#define __kproc_kthread_add						0x466320
#define __sx_init_flags							0x390720
#define __sx_xlock								0x390850
#define __sx_xunlock							0x3909E0
#define __mtx_init								0x3102C0
#define __mtx_lock_spin_flags					0x30FC70
#define __mtx_unlock_spin_flags					0x30FE30
#define __mtx_lock_sleep						0x30F910
#define __mtx_unlock_sleep						0x30FB40
#define __fpu_kern_enter						0x058B60
#define __fpu_kern_leave						0x058C60
#define __kern_reboot							0x098EE0
#define __vm_map_lock_read						0x392ED0
#define __vm_map_lookup_entry					0x393A90
#define __vm_map_unlock_read					0x392F20
#define __vmspace_free							0x392B30
#define __vm_map_delete							0x3955B0
#define __vm_map_protect						0x397680
#define __vmspace_acquire_ref					0x392D00
#define __vm_map_findspace						0x395CB0
#define __vm_map_insert							0x393D90
#define __vm_map_lock							0x392D60
#define __vm_map_unlock 						0x392DD0
#define __proc_rwmem							0x17BDD0

#define __disable_console_output        		0x199FC18
#define __M_TEMP					   			0x199BB80
#define __kernel_map                    		0x1B39218
#define __prison0                       		0x1042AB0
#define __rootvnode                     		0x21B89E0
#define __allproc								0x21B89E0