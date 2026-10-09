typedef int s32;

struct Inner { char pad[0x4]; s32 unk4; };
struct Obj { char pad[0xA0]; Inner *unkA0; };

extern "C" void func_0019A868(Obj *arg0, s32 arg1) {
    arg0->unkA0->unk4 = arg1;
}
