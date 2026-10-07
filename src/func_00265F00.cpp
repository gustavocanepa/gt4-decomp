typedef int s32;
typedef short s16;

struct Obj { char pad[0x9A]; s16 unk9A; };

extern "C" s32 func_00265F00(Obj *arg0) {
    s32 v = arg0->unk9A;
    return v & 1;
}
