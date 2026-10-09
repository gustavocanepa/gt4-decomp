typedef int s32;

struct Inner { char pad[0x8]; s32 unk8; };
struct Obj { char pad[0xA0]; Inner *unkA0; };

extern "C" void func_0019A878(Obj *arg0, s32 arg1) {
    arg0->unkA0->unk8 = arg1;
}
