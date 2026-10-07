typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad[0x4];
    u32 *unk4;
};

extern "C" void func_004A90F0(Obj *arg0) {
    u32 *temp_v1 = arg0->unk4;
    *temp_v1 |= 0x8000;
}
