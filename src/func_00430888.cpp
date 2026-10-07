typedef int s32;

struct Obj {
    char pad[0x4C];
    s32 unk4C;
};

extern "C" void func_00430888(Obj *arg0, s32 arg1) {
    s32 temp_v0 = arg0->unk4C & ~1;
    s32 temp_v1 = temp_v0 | 1;
    arg0->unk4C = (arg1 == 0) ? temp_v0 : temp_v1;
}
