typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct Obj0042CDF8 {
    s32 unk0;
    char pad4[4];
    s32 unk8;
};

extern "C" void func_0042CE18(struct Obj0042CDF8 *arg0, s32 arg1) {
    if ((u32)(u8)arg1 < 8) {
        arg0->unk8 = 1;
        arg0->unk0 = 1;
    }
}
