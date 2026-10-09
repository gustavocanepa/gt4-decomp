typedef float f32;
typedef int s32;

struct S00459D70 {
    s32 unk0;
    f32 unk4;
    f32 unk8;
};

extern "C" void *func_00459D70(S00459D70 *arg0) {
    arg0->unk0 = -1;
    arg0->unk4 = 1.0f;
    arg0->unk8 = 1.0f;
    return arg0;
}
