typedef int s32;
typedef unsigned int u32;

struct S {
    u32 unk0;
    s32 unk4;
};

extern "C" void func_0047E768(S *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = 0x80808080;
}
