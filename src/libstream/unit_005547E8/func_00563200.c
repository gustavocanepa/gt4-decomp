/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned long long u64;

void func_0054D5C8(void);

u32 func_00563200(void) {
    func_0054D5C8();
    *(volatile u32 *)0x10002000 = 0x40000000;
    __asm__ volatile("sync");
    func_0054D5C8();
    return (u32)(*(volatile u64 *)0x10002000 & 0xFFFFFFFF) >> 8;
}
