typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad[0x98];
    u32 unk98;
};

extern "C" void func_00265D30(Obj *arg0) {
    arg0->unk98 = arg0->unk98 | 0x40000;
}
