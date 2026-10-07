typedef int s32;
typedef unsigned int u32;

extern "C" void func_001BB378(s32 arg0, u32 arg1);

extern "C" void func_001BBA78(void) {
    func_001BB378(1, 0xFFFF);
}
