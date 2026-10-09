typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x54C];
    f32 unk54C;
    char pad2[0x6C8 - 0x54C - 4];
    f32 unk6C8;
};

extern "C" f32 func_00350858(void *arg0, Obj *arg1) {
    return arg1->unk6C8 * arg1->unk54C;
}
