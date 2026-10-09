typedef int s32;
typedef unsigned short u16;

struct Obj00491C10 {
    char pad0[0x10];
    u16 unk10;
    char pad1[0x14 - 0x10 - 2];
    s32 *unk14;
};

extern "C" s32 func_00491C10(struct Obj00491C10 *arg0, s32 arg1) {
    s32 idx = (arg1 < (s32)arg0->unk10) ? arg1 : 0;
    return arg0->unk14[idx];
}
