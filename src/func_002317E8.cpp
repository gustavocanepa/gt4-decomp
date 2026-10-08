typedef int s32;
typedef float f32;

struct Obj002317E8 {
    char pad[0x1D00];
    s32 unk1D00;
};

extern "C" void func_002317E8(struct Obj002317E8 *arg0, f32 arg1) {
    *(f32 *)((char *)arg0 + (arg0->unk1D00 * 0x38) + 0x754) = arg1;
}
