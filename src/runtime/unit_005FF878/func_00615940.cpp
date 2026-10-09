typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad[0x4];
    u32 unk4;
    u32 unk8;
};

extern "C" void func_00615940(Obj *arg0) {
    u32 v = arg0->unk4;
    if (v < arg0->unk8) {
        arg0->unk4 = v + 1;
    }
}
