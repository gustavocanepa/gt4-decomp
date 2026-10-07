typedef int s32;

struct Struct00597D98 {
    char pad[0x10];
    s32 unk10;
    s32 unk14;
};

extern "C" Struct00597D98 *func_005AC4D8(void *arg0, s32 arg1);

extern "C" void func_005AC928(void *arg0, s32 arg1) {
    Struct00597D98 *v0 = func_005AC4D8(arg0, 1);
    s32 v1 = 1;
    register Struct00597D98 *a0 asm("$4") = v0;
    a0->unk14 = arg1;
    a0->unk10 = v1;
}
