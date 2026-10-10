typedef unsigned int u32;

int func_005627D0(u32 stat, u32 mask) {
    u32 pcr = *(volatile u32 *)0x1000E020;
    if ((pcr & ~mask) & 0x3FF) {
        return 1;
    }
    *(volatile u32 *)0x1000E020 = pcr | mask;
    __asm__ volatile("sync");
    *(volatile u32 *)0x1000E010 = stat;
    __asm__ volatile("sync");
    return 0;
}
