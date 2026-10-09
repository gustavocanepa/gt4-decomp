typedef unsigned char u8;
typedef int s32;

struct Inner { char pad[0x32]; u8 unk32; };
struct Obj { char pad[0x10]; Inner *unk10; };

extern "C" s32 func_0035C7C8(Obj *arg0) {
    return arg0->unk10->unk32 == 1;
}
