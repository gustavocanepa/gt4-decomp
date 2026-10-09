typedef int s32;
typedef unsigned int u32;

extern "C" void func_00300AB8(s32 arg0, u32 arg1);

extern "C" void func_003011B8(void) {
    func_00300AB8(1, 0xFFFF);
}
