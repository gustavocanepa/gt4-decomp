typedef int s32;
typedef float f32;

struct Dst {
    f32 unk0;
    f32 unk4;
};

struct Src {
    f32 unk0;
    f32 unk4;
};

extern "C" void func_002A3800(char *arg0, s32 arg1, Src *arg2) {
    Dst *dst = (Dst *)(arg0 + arg1 * 8 + 0xCC);
    dst->unk0 = arg2->unk0;
    dst->unk4 = arg2->unk4;
}
