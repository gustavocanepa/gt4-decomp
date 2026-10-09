typedef unsigned char u8;
typedef int s32;

struct Inner { char pad[0x1325]; u8 unk1325; };
struct Obj { char pad[0x50]; Inner *unk50; };

extern "C" s32 func_0060E838(struct Obj *arg0) {
    return arg0->unk50->unk1325 == 1;
}
