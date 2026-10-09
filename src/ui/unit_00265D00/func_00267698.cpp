typedef int s32;
typedef unsigned int u32;

struct Obj { char pad[0x98]; s32 unk98; };

extern "C" s32 func_00267698(Obj *arg0) {
    return ((u32)arg0->unk98 >> 0x17) & 3;
}
