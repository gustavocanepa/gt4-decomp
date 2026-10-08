typedef unsigned char u8;
typedef float f32;

struct Obj {
    char pad0[4];
    char *unk4;
    char pad1[0x544 - 8];
    u8 unk544;
};

extern "C" f32 func_0034A760(struct Obj *arg0) {
    char *p = arg0->unk4 + arg0->unk544 * 0x30;
    return *(f32 *)(p + 0xCAD0);
}
