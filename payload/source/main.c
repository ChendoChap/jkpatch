/* golden */
/* 1/2/2018 */

#include "jkpatch.h"
#include "install.h"

extern uint8_t kpayload[];
extern int32_t kpayload_size;

// perfect for putty
void ascii_art(void *_printf) {
	printf("\n\n");
	printf("   _ _                _       _     \n");
	printf("  (_) | ___ __   __ _| |_ ___| |__  \n");
	printf("  | | |/ / '_ \\ / _` | __/ __| '_ \\ \n");
	printf("  | |   <| |_) | (_| | || (__| | | |\n");
	printf(" _/ |_|\\_\\ .__/ \\__,_|\\__\\___|_| |_|\n");
	printf("|__/     |_|                        \n");
	printf("\n\n");
}

void jailbreak(struct thread *td, uint64_t kernbase) {
	void **prison0 =   (void **)(kernbase + __prison0);
	void **rootvnode = (void **)(kernbase + __rootvnode);

	struct ucred* cred;
	struct filedesc* fd;

	fd = td->td_proc->p_fd;
	cred = td->td_proc->p_ucred;

	cred->cr_uid = 0;
	cred->cr_ruid = 0;
	cred->cr_rgid = 0;
	cred->cr_groups[0] = 0;
	cred->cr_prison = *prison0;
	fd->fd_rdir = fd->fd_jdir = *rootvnode;
}

void debug_patches(struct thread *td, uint64_t kernbase) {
	// sorry... this is very messy!
	// TODO: label and explain patches
	*(uint8_t *)(kernbase + 0x1B6D086) |= 0x14;
	*(uint8_t *)(kernbase + 0x1B6D0A9) |= 0x3;
	*(uint8_t *)(kernbase + 0x1B6D0AA) |= 0x1;
	*(uint8_t *)(kernbase + 0x1B6D0C8) |= 0x1;

	// registry patches for extra debug information
	// fucks with the whole system, patches sceRegMgrGetInt
	// 405
	//*(uint32_t *)(kernbase + 0x4CECB7) = 0;
	//*(uint32_t *)(kernbase + 0x4CFB9B) = 0;
	// 455
	//*(uint32_t *)(kernbase + 0x4D70F7) = 0;
	//*(uint32_t *)(kernbase + 0x4D7F81) = 0;

	// disable sysdump_perform_dump_on_fatal_trap
	// will continue execution and give more information on crash, such as rip
	*(uint8_t *)(kernbase + 0x736250) = 0xC3;

	// patch vm_map_protect check
	memcpy((void *)(kernbase + 0x396A58), "\x90\x90\x90\x90\x90\x90", 6);

	// patch ASLR, thanks 2much4u
	*(uint16_t *)(kernbase + 0x1BA559) = 0x9090;
}

void scesbl_patches(struct thread *td, uint64_t kernbase) {
	char *td_ucred = (char *)td->td_ucred;

	// signed __int64 __fastcall sceSblACMgrGetDeviceAccessType(__int64 a1, __int64 a2, _DWORD *a3)
	// v6 = *(_QWORD *)(a1 + 0x58);
	*(uint64_t *)(td_ucred + 0x58) = 0x3801000000000013; // gives access to everything

	/*
	signed __int64 __fastcall sceSblACMgrIsSystemUcred(__int64 a1) {
		return (*(_QWORD *)(a1 + 0x60) >> 62) & 1LL;
	}
	*/
	*(uint64_t *)(td_ucred + 0x60) = 0xFFFFFFFFFFFFFFFF;

	/*
	__int64 __fastcall sceSblACMgrHasSceProcessCapability(__int64 a1) {
		return *(_QWORD *)(a1 + 0x68) >> 63;
	}
	*/
	*(uint64_t *)(td_ucred + 0x68) = 0xFFFFFFFFFFFFFFFF;

	// sceSblACMgrIsAllowedSystemLevelDebugging
	memcpy((void*)(kernbase + 0x16A530), "\x31\xC0\x40\xC3", 4);
}

int jkpatch(struct thread *td) {
	uint64_t kernbase = getkernbase();
	resolve(kernbase);

	// disable write protect
	uint64_t CR0 = __readcr0();
	__writecr0(CR0 & ~CR0_WP);

	// enable uart
	uint8_t *disable_console_output = (uint8_t *)(kernbase + __disable_console_output);
	*disable_console_output = FALSE;

	// real quick jailbreak ;)
	jailbreak(td, kernbase);

	// quick debug patches
	debug_patches(td, kernbase);

	// sceSblMgr patches
	scesbl_patches(td, kernbase);

	// restore CR0
	__writecr0(CR0);

	// print some stuff
	ascii_art(printf);
	printf("jkpatch installer loaded\n");
	printf("[jkpatch] kernbase 0x%llX\n", kernbase);

	printf("[jkpatch] loading payload...\n");

	// install wizardry
	if (install_payload(td, kernbase, kpayload, kpayload_size)) {
		printf("[jkpatch] install_payload failed!\n");
		return 1;
	}

	printf("[jkpatch] all done!\n");

	return 0;
}

int _main(void) {
	initKernel();
	initLibc();

	// fuck up the updates
	unlink("/update/PS4UPDATE.PUP");
	mkdir("/update/PS4UPDATE.PUP", 777);

	syscall(11, jkpatch);

	// this could race
	/*if (payload) {
		free(payload);
	}*/

	return 0;
}
