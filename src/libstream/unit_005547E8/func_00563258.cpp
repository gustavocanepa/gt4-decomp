/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;

extern "C" void func_0054D5C8(void);

extern "C" void func_00563258(u32 arg) {
    func_0054D5C8();
    *(volatile u32 *)0x10002000 = (arg & 0x7F) | 0x40000000;
    __asm__ volatile("sync");
}
