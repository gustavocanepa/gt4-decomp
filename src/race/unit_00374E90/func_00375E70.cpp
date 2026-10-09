typedef int s32;
typedef float f32;

struct Obj {
    s32 unk0;
    f32 unk4;
};

extern "C" void func_00375E70(Obj *arg0, s32 arg1, f32 fparg0) {
    arg0->unk0 = arg1;
    arg0->unk4 = fparg0;
}
