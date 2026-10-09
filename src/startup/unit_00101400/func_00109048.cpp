typedef int s32;
typedef float f32;

struct Obj00109048 {
    char pad[0x70];
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    s32 unk88;
};

extern "C" void func_00109048(struct Obj00109048 *arg0, s32 arg1, f32 fparg0) {
    arg0->unk70 = arg1;
    arg0->unk74 = 0;
    arg0->unk7C = 0xF;
    arg0->unk78 = 0xF;
    arg0->unk88 = 0xF;
    arg0->unk84 = 0xF;
    arg0->unk80 = (s32)(fparg0 * 30.0f);
}
