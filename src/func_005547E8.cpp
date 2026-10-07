typedef int s32;
typedef unsigned int u32;

struct Obj { char pad[0x18]; u32 unk18; };

extern "C" void func_005547E8(Obj *arg0) {
    arg0->unk18 = arg0->unk18 | 1;
}
