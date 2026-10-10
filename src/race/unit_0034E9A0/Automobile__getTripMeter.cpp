typedef int s32;
typedef float f32;
typedef unsigned char u8;

struct Obj {
    u8 pad0[0x6D4];
    f32 unk6D4;
    u8 pad1[0x7B0 - 0x6D4 - 4];
    f32 unk7B0;
};

extern "C" f32 Automobile__getTripMeter(Obj *arg0, s32 arg1) {
    if (arg1 == 0) {
        return arg0->unk6D4 - arg0->unk7B0;
    }
    if (arg1 == 1) {
        return arg0->unk7B0;
    }
    return arg0->unk6D4;
}
