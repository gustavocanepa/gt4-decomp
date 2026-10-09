typedef int s32;
typedef unsigned int u32;

extern "C" void func_006051F0(void *arg0, s32 arg1) {
    u32 base = (u32)arg0 + 0xC;
    u32 addr0 = (arg1 << 8) + base;
    s32 v = *(s32 *)(addr0 + 0x750);
    u32 addr1 = (arg1 << 2) + base;
    *(s32 *)(addr1 + 0xA50) = v;
}
