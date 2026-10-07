typedef unsigned char u8;
typedef int s32;

struct Inner { char pad[0x234]; u8 unk234; };
struct Obj { char pad[0x10]; Inner *unk10; };

extern "C" s32 func_00355D48(Obj *arg0) {
    return arg0->unk10->unk234 == 7;
}
