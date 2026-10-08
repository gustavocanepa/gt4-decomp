typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad[0x98];
    s32 unk98;
};

extern "C" void func_002665A0(struct Obj *arg0, u32 arg1) {
    arg0->unk98 = (arg0->unk98 & ~0xF) | (arg1 & 0xF);
}
