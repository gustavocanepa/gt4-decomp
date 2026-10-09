typedef int s32;

struct Obj { char pad[0x98]; s32 unk98; };

extern "C" s32 func_00265D00(Obj *arg0) {
    return (arg0->unk98 >> 0xC) & 1;
}
