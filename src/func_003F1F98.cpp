typedef int s32;
typedef unsigned char u8;
typedef unsigned int u32;

struct Obj { char pad[0x12]; u8 unk12; };

extern "C" s32 func_003F1F98(Obj *arg0) {
    return (u32)((arg0->unk12 + 0xFF) & 0xFF) < 2U;
}
