typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x8];
    s32 unk8;
    char pad2[4];
    s32 unk10;
    f32 unk14;
};

extern "C" void func_0021B4F8(struct Obj *arg0, f32 fparg0) {
    if (arg0->unk8 != 0) {
        if (arg0->unk10 != 0) {
            arg0->unk14 = arg0->unk14 + fparg0;
        }
    }
}
