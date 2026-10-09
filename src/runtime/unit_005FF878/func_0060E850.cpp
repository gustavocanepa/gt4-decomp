typedef unsigned char u8;
typedef int s32;

struct Inner { char pad[0x1320]; u8 unk1320; };
struct Obj { char pad[0x50]; Inner *unk50; };

extern "C" s32 func_0060E850(struct Obj *arg0) {
    return arg0->unk50->unk1320 == 1;
}
