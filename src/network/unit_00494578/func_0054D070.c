typedef int s32;

extern void func_005AEB68(s32);

s32 func_0054D070(s32 unused, s32 arg) {
    if (*(volatile s32 *)0x10002010 & 0x4000)
        func_005AEB68(arg);
    __asm__ volatile("sync
	ei");
    return 0;
}
