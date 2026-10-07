typedef int s32;

struct Inner { char pad[0x74]; s32 unk74; };
struct Obj { char pad[0xA0]; Inner *unkA0; };

extern "C" s32 func_0019A830(Obj *arg0) {
    return arg0->unkA0->unk74;
}
