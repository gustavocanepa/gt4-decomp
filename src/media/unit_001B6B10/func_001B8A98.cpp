typedef int s32;
typedef unsigned int u32;

extern "C" void func_001B8378(s32 arg0, u32 arg1);

extern "C" void func_001B8A98(void) {
    func_001B8378(0, 0xFFFF);
}
