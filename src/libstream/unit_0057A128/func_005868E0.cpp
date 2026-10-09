typedef int s32;
typedef unsigned char u8;

struct Obj { char pad[0x14]; u8 unk14; };

extern "C" s32 func_005868E0(Obj *arg0, Obj *arg1) {
    return arg0->unk14 - arg1->unk14;
}
