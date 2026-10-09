typedef int s32;
typedef float f32;

struct Obj_003702E8 {
    char pad[0x4C];
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
};

extern "C" void func_003702E8(Obj_003702E8 *arg0, s32 arg1, f32 *arg2, f32 *arg3) {
    if (arg1 != 0) {
        *arg2 = arg0->unk4C;
        *arg3 = arg0->unk54;
        return;
    }
    *arg2 = arg0->unk50;
    *arg3 = arg0->unk58;
}
