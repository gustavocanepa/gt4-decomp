/* compiler: ee-gcc2.96-no-strict-aliasing */
/* IPU: issue FDEC with no shift and return the top `bits` bits of the decoded data word. */
typedef unsigned int u32;
typedef unsigned long u64;

#define IPU_CMD ((volatile u64 *)0x10002000)

void func_0054D5C8(void);

u32 func_00563198(int bits)
{
    func_0054D5C8();
    *(volatile u32 *)IPU_CMD = 0x40000000;
    __asm__ volatile("sync.l");
    func_0054D5C8();
    return (u32)(*IPU_CMD & 0xFFFFFFFF) >> (32 - bits);
}
