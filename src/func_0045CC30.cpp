typedef int s32;

struct Obj { char pad[0x43C]; s32 unk43C; };

extern "C" s32 func_0045CC30(Obj *arg0) {
    return arg0->unk43C;
}
