typedef int s32;
typedef unsigned char u8;

struct Obj { char pad[0x789]; u8 unk789; };

extern "C" s32 func_0035C828(Obj *arg0) {
    return arg0->unk789 & 0xF;
}
