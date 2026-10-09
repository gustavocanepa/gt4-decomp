typedef unsigned char u8;
typedef int s32;
typedef float f32;

struct Obj003438C8 {
    char pad0[0xC];
    f32 unkC;
    char pad1[0x14 - 0xC - 4];
    u8 unk14;
};

extern "C" void func_003438C8(struct Obj003438C8 *arg0, f32 fparg0) {
    f32 temp_f0;

    if (arg0->unk14 == 0) {
        temp_f0 = arg0->unkC + fparg0;
        arg0->unkC = temp_f0;
        if (temp_f0 > 0.8f) {
            arg0->unkC = 0.8f;
        }
    }
}
