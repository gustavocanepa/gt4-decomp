typedef int s32;

struct Inner { char pad[0x1C]; s32 unk1C; };
struct Obj { char pad[0xA0]; Inner *unkA0; };

extern "C" void func_0019A8B8(Obj *arg0, s32 arg1) {
    arg0->unkA0->unk1C = arg1;
}
