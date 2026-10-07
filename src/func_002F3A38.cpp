typedef int s32;

struct Obj { char pad[0x34]; s32 unk34; };

extern "C" s32 func_002F3A38(Obj *arg0) {
    return arg0->unk34;
}
