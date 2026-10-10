typedef unsigned long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;

#define IPU_CMD 0x10002000

void func_0054D5C8(void);

s16 func_00568610(void) {
    func_0054D5C8();
    *(volatile u32 *)IPU_CMD = 0x38000000;
    __asm__ __volatile__("sync");
    func_0054D5C8();
    return (s16)(u16)(*(volatile u64 *)IPU_CMD & 0xFFFF);
}
