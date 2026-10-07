typedef int s32;

struct Obj { char pad[0x98]; s32 unk98; };

extern "C" s32 func_00266268(Obj *arg0) {
    return (arg0->unk98 >> 25) & 1;
}
