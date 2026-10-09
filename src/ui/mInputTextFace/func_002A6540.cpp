typedef int s32;
typedef unsigned int u32;

struct Obj { char pad[0x164]; s32 unk164; };

extern "C" s32 func_002A6540(Obj *arg0) {
    return (u32)(arg0->unk164 - 2) < 2U;
}
